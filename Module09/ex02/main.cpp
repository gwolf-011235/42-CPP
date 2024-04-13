/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:03:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 11:09:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.hpp"

int	PmergeMe_tests(void);

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: ./pmergeMe [a number of positive integers]\n";
		return (1);
	}

	if (argc == 2 && std::string(argv[1]) == "test") {
		return (PmergeMe_tests());
	}

	try {
		utils::check_args(argc, argv);
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
		return (1);
	}

	PmergeMe pmergeMe(argc, argv);

	pmergeMe.time_for_list();
	pmergeMe.time_for_vector();

	return (0);
}
