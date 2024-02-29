/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:15:11 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/29 22:37:54 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <ctime>
# include <map>
# include <cstdlib>

class BitcoinExchange
{
public:
	BitcoinExchange(const char* filename = "data.csv");
	BitcoinExchange(const BitcoinExchange& ref);
	~BitcoinExchange(void);
	BitcoinExchange& operator= (const BitcoinExchange& ref);

	void		readInputFile(const char* input_file) const;
	double		getExchangeRate(time_t& date) const;
	std::string	convertDate(time_t& date) const;
	void		printData(void) const;
private:
	std::map<time_t, double>	m_database;
};

#endif
