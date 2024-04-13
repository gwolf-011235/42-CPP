/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_johnson_vec.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:26:40 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 11:14:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ford_johnson.hpp"

static bool	compare_GroupIterator(const GroupIterator value, const std::list<GroupIterator>::iterator iter, std::size_t& num_comp)
{
	num_comp++;
	return (*value < **iter);
}

static std::list<GroupIterator>::iterator	binary_insert(std::list<GroupIterator>::iterator begin, std::list<GroupIterator>::iterator end, GroupIterator value, std::size_t& num_comp)
{
	std::ptrdiff_t len = std::distance(begin, end);

	while (len > 0) {
		std::ptrdiff_t half = len >> 1;
		std::list<GroupIterator>::iterator mid = begin;
		std::advance(mid, half);
		if (compare_GroupIterator(value, mid, num_comp)) {
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

static void ford_johnson_vec_impl(GroupIterator first, GroupIterator last, std::size_t& num_comp)
{
	std::size_t size = std::distance(first, last);

	// Exit out of recursion
	if (size < 2) {
		return;
	}

	// Whether there is a stray element not in a pair
	bool has_stray = (size % 2 != 0);

// Step 1: Pairwise comparison

	// The bigger element is put on the left side
	// If there is a stray element, the end iterator is decremented by one
	GroupIterator end = last;
	if (has_stray) {
		end = prev_GroupIterator(last);
	}

	for (GroupIterator it = first; it != end ; ++it) {
		num_comp++;
		if (*it < *next_GroupdIterator(it)) {
			swap_GroupIterator(it, next_GroupdIterator(it));
		}
		if (it != end) {
			++it;
		}
	}

// Step 2: Recursively sort the pairs by max

	ford_johnson_vec_impl(make_GroupIterator(first, 2), make_GroupIterator(end, 2), num_comp);


// Step 3: Separate main chain and pend elements

	std::list<GroupIterator> main;
	std::list<vec_node> pend;

	// The first pend element is always part of the main chain,
	// so we can safely start the list with the first two
	// elements of the sequence
	main.insert(main.end(), next_GroupdIterator(first));
	main.insert(main.end(), first);

	// Add the rest of the elements alternately to main chain and pend chain
	for (GroupIterator it = next_GroupdIterator(first, 2) ; it != end ; ++it) {
		std::list<GroupIterator>::iterator tmp = main.insert(main.end(), it);
		if (it != end) {
			++it;
		}
		pend.push_back(std::make_pair(it, tmp));
	}

	// Add the last element to pend if it exists, when it
	// exists, it always has to be inserted in the full chain,
	// so giving it main.end() as end insertion point is ok
	if (has_stray) {
		pend.push_back(std::make_pair(end, main.end()));
	}

	// Binary insertion into the main chain
	for (int k = 2 ; ; ++k)
	{
		// Find next index
		std::size_t dist = calc_diff_jacobsthal_num(k);
		if (dist >= pend.size()) {
			break;
		}

		std::list<vec_node>::iterator it = pend.begin();
		std::advance(it, dist - 1);

		while (true) {
			std::list<GroupIterator>::iterator insertion_point = binary_insert(main.begin(), it->second, it->first, num_comp);
			main.insert(insertion_point, it->first);

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
		std::list<vec_node>::iterator it = pend.end();
		--it;
		std::list<GroupIterator>::iterator insertion_point = binary_insert(main.begin(), it->second, it->first, num_comp);
		main.insert(insertion_point, it->first);
		pend.pop_back();
	}

	// Copy values in order to a cache then back to origin
	// We only have sorted the iterators, now we need to construct the sorted sequence
	std::vector<unsigned int> cache;
	for (std::list<GroupIterator>::iterator it = main.begin(); it != main.end(); ++it) {
		std::vector<unsigned int>::iterator g_begin = (*it).base();
		std::vector<unsigned int>::iterator g_end = g_begin + (*it).size();
		for (; g_begin != g_end; ++g_begin) {
			cache.push_back(*g_begin);
		}
	}
	std::copy(cache.begin(), cache.end(), first.base());
}

std::size_t	ford_johnson_vec(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	std::size_t num_comp = 0;
	GroupIterator first = make_GroupIterator(begin, 1);
	GroupIterator last = make_GroupIterator(end, 1);
	ford_johnson_vec_impl(first, last, num_comp);
	return (num_comp);
}
