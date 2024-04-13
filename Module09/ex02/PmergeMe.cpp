/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:13:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 11:12:06 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) : m_argc(argc), m_argv(argv)
{
}

//private
PmergeMe::PmergeMe(void) : m_argc(1)
{
	std::cout << "This should not be called\n";
}

//private
PmergeMe::PmergeMe(const PmergeMe& ref) : m_argc(1)
{
	std::cout << "This should not be called\n";
	(void) ref;
}

//private
PmergeMe& PmergeMe::operator=(const PmergeMe& ref)
{
	std::cout << "This should not be called\n";
	(void)ref;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
}

double	PmergeMe::time_for_vector(void) const
{
	std::vector<unsigned int>	vec;
	double						time_for_convert, time_for_sort;
	clock_t						time_required;
	std::size_t					num_comp;

	std::cout << "VECTOR\n";
	time_required = clock();
	for (int i = 1; i < m_argc; ++i) {
		vec.push_back(std::atoi(m_argv[i]));
	}
	time_required = clock() - time_required;
	time_for_convert = (double)time_required/CLOCKS_PER_SEC;

	std::cout << "Before sorting\n";
	utils::print_container(vec);

	time_required = clock();
	num_comp = ford_johnson_vec(vec.begin(), vec.end());
	time_required = clock() - time_required;
	time_for_sort = (double)time_required/CLOCKS_PER_SEC;

	std::cout << "After sorting\n";
	utils::print_container(vec);

	std::cout << std::fixed << "Time for converting:\t" << time_for_convert << " seconds\n";
	std::cout << "Time for sorting:\t" << time_for_sort << " seconds\n";
	std::cout << "Total time:\t\t" << time_for_convert + time_for_sort << " seconds\n";
	std::cout << "Number of comparisons: " << num_comp << "\n\n";

	return (time_for_convert + time_for_sort);
}

double	PmergeMe::time_for_list(void) const
{
	std::list<unsigned int>	list;
	double					time_for_convert, time_for_sort;
	clock_t					time_required;
	std::size_t				num_comp;

	std::cout << "LIST\n";
	time_required = clock();
	for (int i = 1; i < m_argc; ++i) {
		list.push_back(std::atoi(m_argv[i]));
	}
	time_required = clock() - time_required;
	time_for_convert = (double)time_required/CLOCKS_PER_SEC;

	std::cout << "Before sorting\n";
	utils::print_container(list);

	time_required = clock();
	num_comp = ford_johnson_list(list);
	time_required = clock() - time_required;
	time_for_sort = (double)time_required/CLOCKS_PER_SEC;

	std::cout << "After sorting\n";
	utils::print_container(list);

	std::cout << std::fixed << "Time for converting:\t" << time_for_convert << " seconds\n";
	std::cout << "Time for sorting:\t" << time_for_sort << " seconds\n";
	std::cout << "Total time:\t\t" << time_for_convert + time_for_sort << " seconds\n";
	std::cout << "Number of comparisons: " << num_comp << "\n\n";

	return (time_for_convert + time_for_sort);
}
