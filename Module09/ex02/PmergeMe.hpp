/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/03 17:52:39 by gwolf            ###   ########.fr       */
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


// Small node struct for pend elements
typedef std::pair<group_iterator, std::list<group_iterator>::iterator> node;


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
			std::list<group_iterator>::iterator insertion_point = std::upper_bound(chain.begin(), it->second, it->first, compare_iters);
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
		std::list<group_iterator>::iterator insertion_point = std::upper_bound(chain.begin(), it->second, it->first, compare_iters);
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

void	ft_FordJohnsonVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	print_vector("Before:\t", begin, end);
	std::cout << "Comparisons: " << num_comp << "\n";
	group_iterator first = make_group_iterator(begin, 1);
	group_iterator last = make_group_iterator(end, 1);
	merge_insertion_sort(first, last);

	print_vector("After:\t", begin, end);
	std::cout << "Comparisons: " << num_comp << "\n";


}

///////////////////////////////////////
// List version

typedef std::pair<std::list<int>, std::list<int>::iterator> list_node;

void	swap_list_iter(std::list<int>::iterator& lhs, std::list<int>::iterator& rhs)
{
	std::list<int>::iterator tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

std::list<int>::iterator list_iter_next(std::list<int>::iterator it, std::size_t n)
{
	std::advance(it, n);
	return it;
}

void	ford_johnson_list_impl(std::list<int>& list, std::size_t size, std::size_t step)
{
	std::size_t block_half = 1 << step;
	std::size_t block_size = block_half * 2;
	std::size_t block_count = size / (block_size);
	bool has_stray = false;
// not right: 1 block = 2 elements
	if (block_count % 2 != 0) {
		block_count--;
		has_stray = true;
	}

// not right: 1 block = 2 elements
	if (block_count < 2) {
		return;
	}

	std::list<int>::iterator lhs_begin = list.begin();
	std::list<int>::iterator lhs_end = list_iter_next(lhs_begin, block_half);
	std::list<int>::iterator rhs_begin = lhs_end;
	std::list<int>::iterator rhs_end = list_iter_next(rhs_begin, block_half);

	for (std::size_t i = 0; i != block_count; ++i) {
		if (*lhs_begin < *rhs_begin) {
			list.splice(lhs_begin, list, rhs_begin, rhs_end);
			swap_list_iter(lhs_begin, rhs_begin);
			lhs_end = rhs_begin;
		}
		std::advance(lhs_begin, block_size);
		std::advance(lhs_end, block_size);
		std::advance(rhs_begin, block_size);
		std::advance(rhs_end, block_size);
	}

	// Recursion
	ford_johnson_list_impl(list, size, step + 1);

	// Main and pend elements
	std::list<std::list<int>::iterator> main;
	std::list<list_node> pend;

	lhs_begin = list.begin();
	lhs_end = list_iter_next(lhs_begin, block_half);
	rhs_begin = lhs_end;
	rhs_end = list_iter_next(rhs_begin, block_half);

	for (std::size_t i = 0; i != block_count; ++i) {
		main.push_back(lhs_begin);
		pend.push_back(std::make_pair(std::list<int>(rhs_begin, rhs_end), lhs_begin));

		std::advance(lhs_begin, block_size);
		std::advance(lhs_end, block_size);
		std::advance(rhs_begin, block_size);
		std::advance(rhs_end, block_size);
	}
	if (has_stray) {
		std::advance(lhs_begin, block_size);
		std::advance(lhs_end, block_size);
		pend.push_back(std::make_pair(std::list<int>(lhs_begin, lhs_end), list.end()));
	}

	list.splice(*main.begin(), pend.begin()->first);

	print_list("Insert:\t", list.begin(), list.end());



}



void	ford_johnson_list(std::list<int>& list)
{
	print_list("Before:\t", list.begin(), list.end());
	ford_johnson_list_impl(list, list.size(), 0);
	print_list("After:\t", list.begin(), list.end());
}
#endif
