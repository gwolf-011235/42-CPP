/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/30 11:36:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <utility>
# include <algorithm>

#include "GroupIterator.hpp"

int num_comp = 0;

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


// Small node struct for pend elements
struct node
{
	group_iterator it;
	std::list<group_iterator>::iterator next;
};

bool	compare_iters(const group_iterator lhs, const group_iterator rhs)
{
	num_comp++;
	return (*lhs < *rhs);
}

////////////////////////////////////////////////////////////
// Merge-insertion sort

void merge_insertion_sort(group_iterator first, group_iterator last)
{
	std::size_t size = std::distance(first, last);
	if (size < 2) {
		return;
	}

	// Whether there is a stray element not in a pair
	// at the end of the chain
	bool has_stray = (size % 2 != 0);

	////////////////////////////////////////////////////////////
	// Group elements by pairs

	group_iterator end = has_stray ? iter_prev(last) : last;
	for (group_iterator it = first ; it != end ; ++it) {
		num_comp++;
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
	std::list<node> pend;

	for (group_iterator it = iter_next(first, 2) ; it != end ; ++it) {
		std::list<group_iterator>::iterator tmp = chain.insert(chain.end(), it);
		if (it != end) {
			++it;
		}
		pend.push_back((node){it, tmp});
	}

	// Add the last element to pend if it exists, when it
	// exists, it always has to be inserted in the full chain,
	// so giving it chain.end() as end insertion point is ok
	if (has_stray) {
		pend.push_back((node){end, chain.end()});
	}

	////////////////////////////////////////////////////////////
	// Binary insertion into the main chain

	for (int k = 2 ; ; ++k)
	{
		// Find next index
		std::size_t dist = ft_calc_jacobsthal_diff(k);
		if (dist >= pend.size()) {
			break;
		}

		std::list<node>::iterator it = pend.begin();
		std::advance(it, dist - 1);

		while (true) {
			std::list<group_iterator>::iterator insertion_point = std::upper_bound(chain.begin(), it->next, it->it, compare_iters);
			chain.insert(insertion_point, it->it);

			it = pend.erase(it);
			if (it == pend.begin()) {
				break;
			}
			--it;
		}
	}

	// If there are pend elements left, insert them too
	while (not pend.empty())
	{
		std::list<node>::iterator it = pend.end();
		--it;
		std::list<group_iterator>::iterator insertion_point = std::upper_bound(chain.begin(), it->next, it->it, compare_iters);
		chain.insert(insertion_point, it->it);
		pend.pop_back();
	}

	////////////////////////////////////////////////////////////
	// Copy values in order to a cache then back to origin
	std::vector<int> cache;
	for (std::list<group_iterator>::iterator it = chain.begin(); it != chain.end(); ++it) {
		std::vector<int>::iterator g_begin = (*it).base();
		std::vector<int>::iterator g_end = g_begin + (*it).size();
		for (; g_begin != g_end; ++g_begin) {
			cache.push_back(*g_begin);
		}
	}
	std::copy(cache.begin(), cache.end(), first.base());
}

void	ft_FordJohnsonVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	ft_printVector("Before:\t", begin, end);
	std::cout << "Comparisons: " << num_comp << "\n";
	group_iterator first = make_group_iterator(begin, 1);
	group_iterator last = make_group_iterator(end, 1);
	merge_insertion_sort(first, last);

	ft_printVector("After:\t", begin, end);
	std::cout << "Comparisons: " << num_comp << "\n";


}

#endif
