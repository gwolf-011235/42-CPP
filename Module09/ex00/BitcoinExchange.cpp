/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:16:15 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/02 12:59:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isOnlyDigits(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool isValidDate(const std::string& dateStr, time_t& date)
{
	if (dateStr.length() != 10) {
		std::cerr << "ERROR: Invalid date length of <"<< dateStr.length() << ">\n";
		std::cerr << "Expected 10 characters\n";
		return false;
	}

	if (dateStr[4] != '-' || dateStr[7] != '-') {
		std::cerr << "ERROR: Invalid date format: '" << dateStr << "'\n";
		std::cerr << "Expected 'YYYY-MM-DD'\n";
		return false;
	}

	if (!isOnlyDigits(dateStr.substr(0, 4)) || !isOnlyDigits(dateStr.substr(5, 2)) || !isOnlyDigits(dateStr.substr(8, 2))) {
		std::cerr << "ERROR: Invalid date format: '" << dateStr << "'\n";
		std::cerr << "Expected 'YYYY-MM-DD'\n";
		return false;
	}

	int year = std::strtol(dateStr.substr(0, 4).c_str(), NULL, 10);
	int month = std::strtol(dateStr.substr(5, 2).c_str(), NULL, 10);
	int day = std::strtol(dateStr.substr(8, 2).c_str(), NULL, 10);

	if (month < 1 || month > 12) {
		std::cerr << "ERROR: Invalid month: " << month << "\n";
		std::cerr << "Expected positive number\n";
		return false;
	}

	if (day < 1) {
		std::cerr << "ERROR: Invalid day: " << day << "\n";
		std::cerr << "Expected positive number\n";
		return false;
	}

	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 31) {
				std::cerr << "ERROR: Invalid day: " << day << "\n";
				std::cerr << "Expected day <= 31\n";
				return false;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30) {
				std::cerr << "ERROR: Invalid day: " << day << "\n";
				std::cerr << "Expected day <= 30\n";
				return false;
			}
			break;
		case 2:
			if (isLeapYear(year)) {
				if (day > 29) {
					std::cerr << "ERROR: Invalid day: " << day << "\n";
					std::cerr << "Expected day <= 29\n";
					return false;
				}
			} else {
				if (day > 28) {
					std::cerr << "ERROR: Invalid day: " << day << "\n";
					std::cerr << "Expected day <= 28\n";
					return false;
				}
			}
			break;
	}
	static std::tm temp;
	temp.tm_year = year;
	temp.tm_mon = month;
	temp.tm_mday = day;
	date = mktime(&temp);

	return true;
}

bool isValidHeader(const std::string& header, const std::string& begin, const std::string& end, std::string& delim)
{
	if (header.compare(0, begin.length(), begin.c_str()) != 0) {
		std::cerr << "ERROR: Invalid header: '" << header << "'\n";
		std::cerr << "Expected to start with '" << begin << "'\n";
		return false;
	}

	std::string::size_type pos = header.find(end);
	if (pos == std::string::npos) {
		std::cerr << "ERROR: Invalid header: '" << header << "'\n";
		std::cerr << "Expected to end with '" << end << "'\n";
		return false;
	}

	delim = header.substr(4, pos - 4);
	if (delim.length() == 0) {
		std::cerr << "ERROR: Invalid delimiter: '" << delim << "'\n";
		std::cerr << "Expected a non-empty string\n";
		return false;
	}

	if (header.length() != begin.length() + delim.length() + end.length()) {
		std::cerr << "ERROR: Invalid header: '" << header << "'\n";
		std::cerr << "Expected format: '" << begin << "<delimiter>" << end << "'\n";
		return false;
	}
	std::cout << "Delim: '" << delim << "'\n";
	return true;
}

bool isValidValue(const std::string& valueStr, double& value)
{
	// check for empty string
	if (valueStr.length() == 0) {
		std::cerr << "ERROR: Invalid value: '" << valueStr << "'\n";
		std::cerr << "Expected a non-empty string\n";
		return false;
	}

	// values can only contain digits and one decimal point
	bool hasDecimalPoint = false;
	for (size_t i = 0; i < valueStr.length(); ++i) {
		if (!std::isdigit(valueStr[i])) {
			if (valueStr[i] == '.' && !hasDecimalPoint) {
				hasDecimalPoint = true;
			} else {
				std::cerr << "ERROR: Invalid value: '" << valueStr << "'\n";
				std::cerr << "Expected only digits or one decimal point\n";
				return false;
			}
		}
	}

	// decimal point cannot be the first or last character
	if (valueStr[0] == '.' || valueStr[valueStr.length() - 1] == '.') {
		std::cerr << "ERROR: Invalid value: '" << valueStr << "'\n";
		std::cerr << "Expected decimal point to not be first or last character\n";
		return false;
	}

	value = std::strtod(valueStr.c_str(), NULL);
	return true;
}

BitcoinExchange::BitcoinExchange(const char* filename)
{
	std::ifstream infile(filename);
	if (!infile.is_open()) {
		std::cerr << "ERROR: Failed to open file: " << filename << "\n";
		throw std::runtime_error("Failed to open file");
	}
	std::string line, delim;
	std::getline(infile, line);
	if (!isValidHeader(line, "date", "exchange_rate", delim)) {
		infile.close();
		throw std::runtime_error("Bad database header format");
	}

	size_t line_count = 1, valid_count = 0;
	while (std::getline(infile, line)) {
		std::string dateStr, valueStr;
		line_count++;

		// Spalten extrahieren
		std::string::size_type pos = line.find(delim);
		if (pos == std::string::npos) {
			std::cerr << "ERROR: Delimiter not found\n";
			std::cerr << "Invalid line [" << line_count << "]: " << line << "\n\n";
			continue;
		}
		dateStr = line.substr(0, pos);
		valueStr = line.substr(pos + delim.length());

		// Datum parsen
		time_t date;
		if (!isValidDate(dateStr, date)) {
			std::cerr << "Invalid line [" << line_count << "]: " << line << "\n\n";
			continue;
		}

		// Wert parsen
		double value;
		if (!isValidValue(valueStr, value)) {
			std::cerr << "Invalid line [" << line_count << "]: " << line << "\n\n";
			continue;
		}

		m_database[date] = value;
		valid_count++;
	}
	infile.close();
	if (valid_count == 0) {
		std::cerr << "ERROR: No valid data found\n";
		std::cerr << "CRITICAL: Giving up\n";
		throw std::runtime_error("No valid data found");
	}
	std::cout << "Successfully read " << valid_count << " valid lines\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	*this = ref;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	if (this == &ref)
		return *this;
	m_database = ref.m_database;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

std::string	BitcoinExchange::convertDate(const time_t& date) const
{
	std::tm* date_tm = std::localtime(&date);
	std::stringstream ss;
	ss << date_tm->tm_year << "-";
	if (date_tm->tm_mon < 10)
		ss << 0;
	ss << date_tm->tm_mon << "-";
	if (date_tm->tm_mday < 10)
		ss << 0;
	ss << date_tm->tm_mday;
	return ss.str();
}

double	BitcoinExchange::getExchangeRate(const time_t& date) const
{
	std::map<time_t, double>::const_iterator it = m_database.lower_bound(date);
	if (it->first != date && it != m_database.begin()) {
		--it;
	}
	if (it == m_database.end()) {
		std::cerr << "ERROR: No suitable exchange rate found for date: " << convertDate(date) << "\n";
		return -1;
	}
	return it->second;
}

void	BitcoinExchange::readInputFile(const char* input_file) const
{
	std::ifstream infile(input_file);
	if (!infile.is_open()) {
		std::cerr << "ERROR: Failed to open file <" << input_file << ">\n";
		throw std::runtime_error("Failed to open file");
	}
	std::string line, delim;
	std::getline(infile, line);
	if (!isValidHeader(line, "date", "value", delim)) {
		infile.close();
		throw std::runtime_error("Bad input file header format");
	}

	size_t line_count = 1;
	while (std::getline(infile, line)) {
		std::string dateStr, valueStr;
		line_count++;

		// Spalten extrahieren
		std::string::size_type pos = line.find(delim);
		if (pos == std::string::npos) {
			std::cerr << "ERROR: Delimiter not found\n";
			std::cerr << "Invalid line [" << line_count << "]: " << line << "\n\n";
			continue;
		}
		dateStr = line.substr(0, pos);
		valueStr = line.substr(pos + delim.length());

		// Datum parsen
		time_t date;
		if (!isValidDate(dateStr, date)) {
			std::cerr << "Invalid line [" << line_count << "]: " << line << "\n\n";
			continue;
		}

		// Wert parsen
		double value;
		if (!isValidValue(valueStr, value)) {
			std::cerr << "Invalid line [" << line_count << "]: " << line << "\n\n";
			continue;
		}
		if (value < 0 || value > 1000) {
			std::cerr << "ERROR: ";
			if (value < 0)
				std::cerr << "Value to low\n";
			else
				std::cerr << "Value to high\n";
			std::cerr << "Invalid line [" << line_count << "]: " << line << "\n\n";
			continue;
		}

		double rate = getExchangeRate(date);
		if (rate < 0) {
			std::cerr << "Invalid line [" << line_count << "]: " << line << "\n\n";
			continue;
		}
		std::cout << convertDate(date) << "=> " << value << " (" << rate << ") = " << (value * rate) << "\n";
	}
}

void	BitcoinExchange::printData(void) const
{
	for (std::map<time_t, double>::const_iterator it = m_database.begin(); it != m_database.end(); ++it) {
		std::cout << convertDate(it->first) << ": " << it->second << "\n";
	}
}
