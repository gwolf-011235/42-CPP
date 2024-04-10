/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:13:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/09 17:56:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const int argc, const char **argv) : m_argc(argc)
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [number] [number] ... \n";
		exit(1);
	}
	for (int i = 0; i < argc; ++i) {
		m_argv_as_string[i] = argv[i];
		if (m_argv_as_string[i].find_first_not_of("0123456789") != std::string::npos) {
			std::cerr << "Only numbers [0123456789] are allowed as input: " << m_argv_as_string[i] << '\n';
		}
	}
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
	std::cout << "Destructor called: PmergeMe \n";
}


void	print_vector(std::string str, std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::cout << str;
	for (; begin != end; begin++) {
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
}

void	print_list(std::string str, std::list<int>::iterator begin, std::list<int>::iterator end)
{
	std::cout << str;
	for (; begin != end; begin++) {
		std::cout << *begin << " ";
	}
	std::cout << '\n';
}

size_t	ft_jacobsthal(size_t n)
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

size_t	ft_calc_jacobsthal_diff(size_t n)
{
	return ft_jacobsthal(n + 1) - ft_jacobsthal(n);
}
