/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:15:11 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/26 10:51:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& ref);
	~BitcoinExchange(void);
	BitcoinExchange& operator= (const BitcoinExchange& ref);
private:
	/* data */
};

#endif
