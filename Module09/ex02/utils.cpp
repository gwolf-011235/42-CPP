/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:12:03 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/10 13:22:59 by gwolf            ###   ########.fr       */
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

std::size_t	utils::ft_jacobsthal(std::size_t n)
{
	// base case
	if (n == 0)
		return 0;

	// base case
	if (n == 1)
		return 1;

	// recursive step.
	return ft_jacobsthal(n - 1) + 2 * ft_jacobsthal(n - 2);
}

std::size_t	utils::ft_calc_jacobsthal_diff(std::size_t n)
{
	return utils::ft_jacobsthal(n + 1) - utils::ft_jacobsthal(n);
}
