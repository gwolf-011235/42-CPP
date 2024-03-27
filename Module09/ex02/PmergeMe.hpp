/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/27 18:07:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <utility>
# include <algorithm>

void	ft_printVector(std::string str, std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::cout << str;
	for (; begin != end; begin++) {
		std::cout << *begin << " ";
	}
	std::cout << std::endl;
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


#include <algorithm>
#include <cstddef>
#include <functional>
#include <list>
#include <iterator>

#include "GroupIterator.hpp"

bool	compare_iters(const group_iterator lhs, const group_iterator rhs)
{
	return (*lhs < *rhs);
}

////////////////////////////////////////////////////////////
// Merge-insertion sort

void merge_insertion_sort(group_iterator first, group_iterator last)
{
	std::size_t size = std::distance(first, last);
	if (size < 2) return;

	// Whether there is a stray element not in a pair
	// at the end of the chain
	bool has_stray = (size % 2 != 0);

	////////////////////////////////////////////////////////////
	// Group elements by pairs

	group_iterator end = has_stray ? iter_prev(last) : last;
	for (group_iterator it = first ; it != end ; ++it) {
		if (*it < *iter_next(it)) {
			iter_swap(it, iter_next(it));
		}
		if (it != end) {
			++it;
		}
	}

	////////////////////////////////////////////////////////////
	// Recursively sort the pairs by max

	merge_insertion_sort(make_group_iterator(first, 2), make_group_iterator(end, 2));

	////////////////////////////////////////////////////////////
	// Separate main chain and pend elements

	// The first pend element is always part of the main chain,
	// so we can safely initialize the list with the first two
	// elements of the sequence
	std::list<group_iterator> chain;

	chain.insert(chain.end(), iter_next(first));
	chain.insert(chain.end(), first);

	// Upper bounds for the insertion of pend elements
	std::vector<std::list<group_iterator>::iterator> pend;
	pend.reserve((size + 1) / 2 - 1);

	for (group_iterator it = iter_next(first, 2) ; it != end ; ++it) {
		std::list<group_iterator>::iterator tmp = chain.insert(chain.end(), it);
		pend.push_back(tmp);
		if (it != end) {
			++it;
		}
	}

	// Add the last element to pend if it exists, when it
	// exists, it always has to be inserted in the full chain,
	// so giving it chain.end() as end insertion point is ok
	if (has_stray) {
		pend.push_back(chain.end());
	}

	////////////////////////////////////////////////////////////
	// Binary insertion into the main chain

	group_iterator current_it = iter_next(first, 2);
	std::vector<std::list<group_iterator>::iterator>::iterator current_pend = pend.begin();

	for (int k = 2 ; ; ++k)
	{
		// Find next index
		std::size_t dist = ft_calc_jacobsthal_diff(k);
		if (dist > static_cast<std::size_t>(std::distance(current_pend, pend.end()))) {
			break;
		}

		group_iterator it = iter_next(current_it, dist * 2);
		std::vector<std::list<group_iterator>::iterator>::iterator pe = current_pend;
		std::advance(pe, dist);

		do
		{
			--pe;
			it = iter_prev(it, 2);

			std::list<group_iterator>::iterator insertion_point = std::upper_bound(chain.begin(), *pe, it, compare_iters);
			chain.insert(insertion_point, it);

		} while (pe != current_pend);

		std::advance(current_it, dist * 2);
		std::advance(current_pend, dist);
	}

	// If there are pend elements left, insert them into
	// the main chain, the order of insertion does not
	// matter so forward traversal is ok
	while (current_pend != pend.end())
	{
		std::list<group_iterator>::iterator insertion_point = std::upper_bound(chain.begin(), *current_pend, current_it, compare_iters);
		chain.insert(insertion_point, current_it);
		std::advance(current_it, 2);
		++current_pend;
	}

	////////////////////////////////////////////////////////////
	// Copy values in order to a cache then back to origin
	std::vector<int> cache;
	for (std::list<group_iterator>::iterator it = chain.begin(); it != chain.end(); ++it) {
		std::vector<int>::iterator begin = (*it).base();
		std::vector<int>::iterator end = begin + (*it).size();
		std::copy(begin, end, std::back_inserter(cache));
	}
	std::copy(cache.begin(), cache.end(), first);


}

void	ft_FordJohnsonVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	ft_printVector("Starting point: ", begin, end);
	group_iterator first = make_group_iterator(begin, 1);
	group_iterator last = make_group_iterator(end, 1);
	merge_insertion_sort(first, last);

	ft_printVector("After insertion sort: ", begin, end);

}

#endif
