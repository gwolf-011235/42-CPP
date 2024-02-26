/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:14:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/26 13:20:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2 && argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <filename>\n";
		return (1);
	}

	std::string filename = "data.csv";
	if (argc == 3)
		filename = argv[2];

	BitcoinExchange	btc(filename.c_str());
	btc.printData();

	return (0);
}
