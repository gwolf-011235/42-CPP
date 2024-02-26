/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:14:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/26 11:45:18 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>

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

bool isValidDate(const std::string& dateStr, std::tm& date)
{
	if (dateStr.length() != 10) {
		return false;
	}

	if (dateStr[4] != '-' || dateStr[7] != '-') {
		return false;
	}

	if (!isOnlyDigits(dateStr.substr(0, 4)) || !isOnlyDigits(dateStr.substr(5, 2)) || !isOnlyDigits(dateStr.substr(8, 2))) {
		return false;
	}

	int year = std::strtol(dateStr.substr(0, 4).c_str(), NULL, 10);
	int month = std::strtol(dateStr.substr(5, 2).c_str(), NULL, 10);
	int day = std::strtol(dateStr.substr(8, 2).c_str(), NULL, 10);

	if (month < 1 || month > 12) {
		return false;
	}

	if (day < 1) {
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
				return false;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30) {
				return false;
			}
			break;
		case 2:
			if (isLeapYear(year)) {
				if (day > 29) {
					return false;
				}
			} else {
				if (day > 28) {
					return false;
				}
			}
			break;
	}
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;

	return true;
}



int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	std::ifstream infile("data.csv");
	std::string line;

	while (std::getline(infile, line)) {
		std::stringstream ss(line);
		std::string dateStr, valueStr;

		// Spalten extrahieren
		std::getline(ss, dateStr, ',');
		std::getline(ss, valueStr);

		// Datum parsen
		std::tm date;
		if (!isValidDate(dateStr, date)) {
			std::cerr << "Ungültiges Datum: " << dateStr << "\n";
			continue;
		}

		// Wert parsen
		double value = std::strtod(valueStr.c_str(), NULL);

		// Ausgabe
		std::cout << "Datum: " << date.tm_year + 1900 << "-" << date.tm_mon + 1 << "-" << date.tm_mday << std::endl;
		std::cout << "Wert: " << value << std::endl;
	}
	return (0);
}
