/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:03:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 11:22:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.hpp"

#define AVG_NUM 3

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

	double avg_time_vector = 0;
	double avg_time_list = 0;
	std::cout << "Running algorithm for vector and list " << AVG_NUM << " times\n";
	for (int i = 0; i < AVG_NUM; ++i) {
		avg_time_vector += pmergeMe.time_for_vector();
		avg_time_list += pmergeMe.time_for_list();
	}
	avg_time_vector /= AVG_NUM;
	avg_time_list /= AVG_NUM;
	std::cout << "Average time for vec:\t" << avg_time_vector << '\n';
	std::cout << "Average time for list:\t" << avg_time_list << '\n';

	return (0);
}
