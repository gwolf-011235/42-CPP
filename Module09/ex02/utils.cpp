/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:12:03 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 11:09:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	utils::check_args(const int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [integers...]\n";
		throw std::runtime_error("Invalid arguments");
	}
	if (argc > 1000000) {
		std::cerr << "Too many arguments\n";
		throw std::runtime_error("Invalid arguments");
	}
	for (int i = 1; i < argc; ++i) {
		for (int j = 0; argv[i][j] != '\0'; ++j) {
			if (!std::isdigit(argv[i][j])) {
				std::cerr << "Invalid argument: " << argv[i] << '\n';
				throw std::runtime_error("Invalid arguments");
			}
		}
	}
}
