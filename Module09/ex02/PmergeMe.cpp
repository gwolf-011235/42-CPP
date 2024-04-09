/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:13:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/09 08:37:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
