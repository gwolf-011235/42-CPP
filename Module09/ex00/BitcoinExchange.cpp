/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:16:15 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/26 11:46:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
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

