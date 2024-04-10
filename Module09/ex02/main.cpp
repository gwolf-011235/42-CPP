/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:03:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/10 16:35:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.hpp"

int	test(void);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (test());

	try {
		utils::check_args(argc, argv);
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
		return (1);
	}

	PmergeMe pmergeMe(argc, argv);

	pmergeMe.time_for_vector();
	pmergeMe.time_for_list();

	return (0);
}
