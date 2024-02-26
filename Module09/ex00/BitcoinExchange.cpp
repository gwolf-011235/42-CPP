/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:16:15 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/26 14:21:36 by gwolf            ###   ########.fr       */
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
		std::cerr << "ERROR\n";
		std::cerr << "Invalid date length: '" << dateStr << "'\n";
		std::cerr << "Expected 10 characters\n";
		return false;
	}

	if (dateStr[4] != '-' || dateStr[7] != '-') {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid date format: '" << dateStr << "'\n";
		std::cerr << "Expected 'YYYY-MM-DD'\n";
		return false;
	}

	if (!isOnlyDigits(dateStr.substr(0, 4)) || !isOnlyDigits(dateStr.substr(5, 2)) || !isOnlyDigits(dateStr.substr(8, 2))) {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid date format: '" << dateStr << "'\n";
		std::cerr << "Expected 'YYYY-MM-DD'\n";
		return false;
	}

	int year = std::strtol(dateStr.substr(0, 4).c_str(), NULL, 10);
	int month = std::strtol(dateStr.substr(5, 2).c_str(), NULL, 10);
	int day = std::strtol(dateStr.substr(8, 2).c_str(), NULL, 10);

	if (month < 1 || month > 12) {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid month: " << month << "\n";
		return false;
	}

	if (day < 1) {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid day: " << day << "\n";
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
				std::cerr << "ERROR\n";
				std::cerr << "Invalid day: " << day << "\n";
				return false;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30) {
				std::cerr << "ERROR\n";
				std::cerr << "Invalid day: " << day << "\n";
				return false;
			}
			break;
		case 2:
			if (isLeapYear(year)) {
				if (day > 29) {
					std::cerr << "ERROR\n";
					std::cerr << "Invalid day: " << day << "\n";
					return false;
				}
			} else {
				if (day > 28) {
					std::cerr << "ERROR\n";
					std::cerr << "Invalid day: " << day << "\n";
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

bool isValidHeader(const std::string& header, std::string& delim)
{
	if (header.compare(0, 4, "date") != 0) {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid header: '" << header << "'\n";
		std::cerr << "Expected 'date'\n";
		return false;
	}
	std::string::size_type pos = header.find("exchange_rate");
	if (header.find("exchange_rate") == std::string::npos) {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid header: '" << header << "'\n";
		std::cerr << "Expected 'exchange_rate'\n";
		return false;
	}
	delim = header.substr(4, pos - 4);
	std::cout << "Delim: '" << delim << "'\n";
	return true;
}

bool isValidValue(const std::string& valueStr, double& value)
{
	if (valueStr.length() == 0) {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid value: '" << valueStr << "'\n";
		return false;
	}

	if (valueStr[0] == '-') {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid value: '" << valueStr << "'\n";
		std::cerr << "Expected positive value\n";
		return false;
	}
	//do we not do this?
	if (valueStr[0] == '+') {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid value: '" << valueStr << "'\n";
		std::cerr << "Expected positive value\n";
		return false;
	}
	// doesn't seem to work.
	if (valueStr[0] == '0' && valueStr.length() > 1 && valueStr[1] != '.') {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid value: '" << valueStr << "'\n";
		std::cerr << "Expected positive value\n";
		return false;
	}

	if (valueStr[valueStr.length() - 1] == '.') {
		std::cerr << "ERROR\n";
		std::cerr << "Invalid value: '" << valueStr << "'\n";
		std::cerr << "Expected digit after decimal point\n";
		return false;
	}

	for (size_t i = 0; i < valueStr.length(); ++i) {
		if (!std::isdigit(valueStr[i]) && valueStr[i] != '.') {
			std::cerr << "ERROR\n";
			std::cerr << "Invalid value: '" << valueStr << "'\n";
			std::cerr << "Expected only digits or decimal point\n";
			return false;
		}
	}

	value = std::strtod(valueStr.c_str(), NULL);
	return true;
}

BitcoinExchange::BitcoinExchange(const char* filename)
{
	std::ifstream infile(filename);
	std::string line, delim;
	std::getline(infile, line);
	if (!isValidHeader(line, delim)) {

		return;
	}

	while (std::getline(infile, line)) {
		std::string dateStr, valueStr;

		// Spalten extrahieren
		std::string::size_type pos = line.find(delim);
		if (pos == std::string::npos) {
			std::cerr << "ERROR\n";
			std::cerr << "Delimiter not found\n";
			std::cerr << "Invalid line: " << line << "\n\n";
			continue;
		}
		dateStr = line.substr(0, pos);
		valueStr = line.substr(pos + 1);

		// Datum parsen
		time_t date;
		if (!isValidDate(dateStr, date)) {
			std::cerr << "Invalid line: " << line << "\n\n";
			continue;
		}

		// Wert parsen
		double value;
		if (!isValidValue(valueStr, value)) {
			std::cerr << "Invalid line: " << line << "\n\n";
			continue;
		}

		m_database[date] = value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	*this = ref;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	(void)ref;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void	BitcoinExchange::printData(void) const
{
	for (std::map<time_t, double>::const_iterator it = m_database.begin(); it != m_database.end(); ++it) {
		std::tm* date = std::localtime(&it->first);
		std::cout << date->tm_year << "-" << date->tm_mon << "-" << date->tm_mday << ": " << it->second << "\n";
	}
}