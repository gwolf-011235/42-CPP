/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:14:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/06 11:32:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2 && argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <input_filename>\n";
		return (1);
	}

	std::string database_filename = "database/data.csv";
	if (argc == 3)
		database_filename = argv[2];

	try {
		BitcoinExchange	btc(database_filename.c_str());
		btc.readInputFile(argv[1]);
	}
	catch (const std::exception& e) {
		std::cerr << "CRITICAL: " << e.what() << "\n";
		return (1);
	}

	return (0);
}
