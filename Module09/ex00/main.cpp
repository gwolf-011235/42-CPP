/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:14:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/29 23:00:51 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2 && argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <input_filename>\n";
		return (1);
	}

	std::string database_filename = "database/data.csv";
	if (argc == 3)
		database_filename = argv[2];

	BitcoinExchange	btc(database_filename.c_str());
	btc.readInputFile(argv[1]);

	return (0);
}
