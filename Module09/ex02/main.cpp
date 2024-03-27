/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:03:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/27 16:13:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <cstdlib>

int	main(int argc, char **argv)
{
	std::vector<int>	vec;
	for (int i = 1; argc > 1; ++i) {
		vec.push_back(std::atoi(argv[i]));
		argc--;
	}
	ft_FordJohnsonVector(vec.begin(), vec.end());
	return (0);
}
