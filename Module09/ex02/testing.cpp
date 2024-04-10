/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:13:48 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/10 15:14:33 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

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
	std::vector<unsigned int> vec;
	std::list<unsigned int> lst;
	std::size_t vec_comp, lst_comp;

	for (std::size_t i = 0; i < numbers; ++i) {
		unsigned int n = drand() * 100000;
		vec.push_back(n);
		lst.push_back(n);
	}

	vec_comp = ford_johnson_vec(vec.begin(), vec.end());

	if (vec_comp > max_comp) {
		std::cerr << "Vector: " << vec_comp << " > " << max_comp << '\n';
		std::cerr << "Testcase:\n";
		utils::print_container(vec);
		return (false);
	}

	if (!is_sorted(vec)) {
		std::cerr << "Vector is not sorted\n";
		std::cerr << "Testcase:\n";
		utils::print_container(vec);
		return (false);
	}

	lst_comp = ford_johnson_list(lst);

	if (lst_comp > max_comp) {
		std::cerr << "List: " << lst_comp << " > " << max_comp << '\n';
		std::cerr << "Testcase:\n";
		utils::print_container(lst);
		return (false);
	}

	if (!is_sorted(lst)) {
		std::cerr << "List is not sorted\n";
		std::cerr << "Testcase:\n";
		utils::print_container(lst);
		return (false);
	}

	return (true);
}

int	test(void)
{
	std::srand(std::time(0));

	for (int i = 0; i < 100; ++i) {
		if (!test_case(5, 7)) {
			std::cerr << "Test failed\n";
			return (1);
		}
	}
	std::cout << "All tests passed\n";
	return (0);
}
