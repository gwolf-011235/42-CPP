/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:15:11 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/12 15:05:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <fstream>
# include <sstream>
# include <ctime>
# include <map>
# include <cstdlib>
# include <stdexcept>

class BitcoinExchange
{
public:
	BitcoinExchange(const char* filename = "data.csv");
	~BitcoinExchange(void);

	void	readInputFile(const char* input_file) const;
	double	getExchangeRate(const time_t& date) const;
	void	printData(void) const;
private:
	BitcoinExchange(const BitcoinExchange& ref);
	BitcoinExchange& operator= (const BitcoinExchange& ref);

	bool		parseHeader(const std::string& header, const std::string& begin, const std::string& end, std::string& delim) const;
	bool		parseLine(const std::string& line, const std::string& delim, time_t& date, double& value) const;
	std::string	convertDateToString(const time_t& date) const;

	std::map<time_t, double>	m_database;
};

#endif
