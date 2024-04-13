/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:13:48 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 10:05:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

#define NUM_RUNS 1000
#define RS_SCALE (1.0 / (1.0 + RAND_MAX))

double drand(void)
{
	double d;
	do {
	   d = (((rand () * RS_SCALE) + rand ()) * RS_SCALE + rand ()) * RS_SCALE;
	} while (d >= 1); /* Round off */
	return(d);
}

template <typename T>
bool	is_sorted(const T &t)
{
	typename T::const_iterator pos = std::adjacent_find (t.begin(), t.end(), std::greater<int>());

	if (pos == t.end())
		return (true);
	return (false);
}

bool	test_case(std::size_t numbers, std::size_t max_comp)
{
	std::cout << "Testcase: " << numbers << " numbers with max comparisons of " << max_comp << '\n';
	std::vector<unsigned int> vec, check;
	std::list<unsigned int> lst;
	std::size_t vec_comp, lst_comp;

	for (std::size_t i = 0; i < numbers; ++i) {
		unsigned int n = drand() * 100000;
		vec.push_back(n);
		lst.push_back(n);
		check.push_back(n);
	}

	vec_comp = ford_johnson_vec(vec.begin(), vec.end());

	if (max_comp > 0 && vec_comp > max_comp) {
		std::cerr << "Vector: " << vec_comp << " > " << max_comp << '\n';
		std::cerr << "Testcase:\n";
		utils::print_container(check);
		std::cerr << "Result:\n";
		utils::print_container(vec);
		return (false);
	}

	if (!is_sorted(vec)) {
		std::cerr << "Vector is not sorted\n";
		std::cerr << "Testcase:\n";
		utils::print_container(check);
		std::cerr << "Result:\n";
		utils::print_container(vec);
		return (false);
	}

	lst_comp = ford_johnson_list(lst);

	if (max_comp > 0 && lst_comp > max_comp) {
		std::cerr << "List: " << lst_comp << " > " << max_comp << '\n';
		std::cerr << "Testcase:\n";
		utils::print_container(check);
		std::cerr << "Result:\n";
		utils::print_container(lst);
		return (false);
	}

	if (!is_sorted(lst)) {
		std::cerr << "List is not sorted\n";
		std::cerr << "Testcase:\n";
		utils::print_container(check);
		std::cerr << "Result:\n";
		utils::print_container(lst);
		return (false);
	}

	std::cout << "Testcase passed\n";
	return (true);
}

int	PmergeMe_tests(void)
{
	std::cout << "Running tests\n";
	std::cout << "Number of runs: " << NUM_RUNS << '\n';

	std::srand(std::time(0));

	for (int i = 0; i < NUM_RUNS; ++i) {
		std::cout << "Run: " << i << '\n';
		if (!test_case(1, 0) ||
			!test_case(2, 1) ||
			!test_case(3, 3) ||
			!test_case(4, 5) ||
			!test_case(5, 7) ||
			!test_case(6, 10) ||
			!test_case(7, 13) ||
			!test_case(8, 16) ||
			!test_case(9, 19) ||
			!test_case(10, 22) ||
			!test_case(11, 26) ||
			!test_case(12, 30) ||
			!test_case(13, 34) ||
			!test_case(14, 38) ||
			!test_case(15, 42) ||
			!test_case(16, 46) ||
			!test_case(17, 50) ||
			!test_case(18, 54) ||
			!test_case(19, 58) ||
			!test_case(20, 62) ||
			!test_case(21, 66) ||
			!test_case(22, 71) ||
			!test_case(3000, 0)) {
			std::cerr << "Test failed\n";
			return (1);
		}
	}
	std::cout << "All tests passed\n";
	return (0);
}
