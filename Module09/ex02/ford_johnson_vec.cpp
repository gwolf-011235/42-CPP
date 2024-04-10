/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_johnson_vec.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:26:40 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/09 17:33:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "GroupIterator.hpp"

// Small node struct for pend elements
typedef std::pair<group_iterator, std::list<group_iterator>::iterator> node;


bool	compare_group_iter(const group_iterator value, const std::list<group_iterator>::iterator iter, std::size_t& num_comp)
{
	num_comp++;
	return (*value < **iter);
}

std::list<group_iterator>::iterator	binary_insert(std::list<group_iterator>::iterator begin, std::list<group_iterator>::iterator end, group_iterator value, std::size_t& num_comp)
{
	std::ptrdiff_t len = std::distance(begin, end);

	while (len > 0) {
		std::ptrdiff_t half = len >> 1;
		std::list<group_iterator>::iterator mid = begin;
		std::advance(mid, half);
		if (compare_group_iter(value, mid, num_comp)) {
			len = half;
		}
		else {
			begin = mid;
			++begin;
			len = len - half - 1;
		}
	}
	return begin;
}


////////////////////////////////////////////////////////////
// Merge-insertion sort

void ford_johnson_vec_impl(group_iterator first, group_iterator last, std::size_t& num_comp)
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

	ford_johnson_vec_impl(make_group_iterator(first, 2), make_group_iterator(end, 2), num_comp);

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
		pend.push_back(std::make_pair(it, tmp));
	}

	// Add the last element to pend if it exists, when it
	// exists, it always has to be inserted in the full chain,
	// so giving it chain.end() as end insertion point is ok
	if (has_stray) {
		pend.push_back(std::make_pair(end, chain.end()));
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
			std::list<group_iterator>::iterator insertion_point = binary_insert(chain.begin(), it->second, it->first, num_comp);
			chain.insert(insertion_point, it->first);

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
		std::list<group_iterator>::iterator insertion_point = binary_insert(chain.begin(), it->second, it->first, num_comp);
		chain.insert(insertion_point, it->first);
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

std::size_t	ford_johnson_vec(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::size_t num_comp = 0;
	group_iterator first = make_group_iterator(begin, 1);
	group_iterator last = make_group_iterator(end, 1);
	ford_johnson_vec_impl(first, last, num_comp);
	return (num_comp);
}
