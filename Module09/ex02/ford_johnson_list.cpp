/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_johnson_list.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:17:17 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/10 13:41:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

typedef struct list_node
{
	std::list<std::list<unsigned int>::iterator>::iterator pair_head;
	std::list<unsigned int>::iterator begin;
	std::list<unsigned int>::iterator end;
}	list_node;

bool	compare_list_iter(std::list<unsigned int>::iterator value, std::list<std::list<unsigned int>::iterator>::iterator iter, std::size_t& num_comp)
{
	num_comp++;
	return (*value < **iter);
}

void	swap_list_iter(std::list<unsigned int>::iterator& lhs, std::list<unsigned int>::iterator& rhs)
{
	std::list<unsigned int>::iterator tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

std::list<unsigned int>::iterator next_list_iter(std::list<unsigned int>::iterator it, std::size_t n)
{
	std::advance(it, n);
	return it;
}

std::list<std::list<unsigned int>::iterator>::iterator	binary_insert(std::list<std::list<unsigned int>::iterator>::iterator begin, std::list<std::list<unsigned int>::iterator>::iterator end, std::list<unsigned int>::iterator value, std::size_t& num_comp)
{
	std::ptrdiff_t len = std::distance(begin, end);

	while (len > 0) {
		std::ptrdiff_t half = len >> 1;
		std::list<std::list<unsigned int>::iterator>::iterator mid = begin;
		std::advance(mid, half);
		if (compare_list_iter(value, mid, num_comp)) {
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

list_node make_list_node(std::list<std::list<unsigned int>::iterator>::iterator pair_head, std::list<unsigned int>::iterator begin, std::list<unsigned int>::iterator end)
{
	list_node temp = {pair_head, begin, end};
	return temp;
}

void	ford_johnson_list_impl(std::list<unsigned int>& list, std::size_t size, std::size_t step, std::size_t& num_comp)
{
// Pairwise comparison
// One element is the lhs or rhs of a pairwise comparison
	std::size_t elem_size = 1 << step;
	std::size_t block_size = elem_size * 2;
	std::size_t elem_count = size / (elem_size);
	bool has_stray = false;
	if (elem_count % 2 != 0) {
		elem_count--;
		has_stray = true;
	}

// exit out of recursion
	if (elem_count < 2) {
		return;
	}

	std::list<unsigned int>::iterator lhs_begin = list.begin();
	std::list<unsigned int>::iterator lhs_end = next_list_iter(lhs_begin, elem_size);
	std::list<unsigned int>::iterator rhs_begin = lhs_end;
	std::list<unsigned int>::iterator rhs_end = next_list_iter(rhs_begin, elem_size);

	for (std::size_t i = 0; i != elem_count; i += 2) {
		num_comp++;
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
	ford_johnson_list_impl(list, size, step + 1, num_comp);

	// Main and pend elements
	std::list<std::list<unsigned int>::iterator> main;
	std::list<list_node> pend;

	lhs_begin = list.begin();
	lhs_end = next_list_iter(lhs_begin, elem_size);
	rhs_begin = lhs_end;
	//remember end - 1 because actual end can shift around
	rhs_end = next_list_iter(rhs_begin, elem_size - 1);

	for (std::size_t i = 0; i != elem_count; i += 2) {
		main.push_back(lhs_begin);
		pend.push_back(make_list_node(--(main.end()), rhs_begin, rhs_end));

		std::advance(lhs_begin, block_size);
		std::advance(lhs_end, block_size);
		std::advance(rhs_begin, block_size);
		std::advance(rhs_end, block_size);
	}
	if (has_stray) {
		--lhs_end;
		list_node temp = {main.end(), lhs_begin, lhs_end};
		pend.push_back(temp);
	}

	list.splice(*pend.begin()->pair_head, list, pend.begin()->begin, ++(pend.begin()->end));
	main.insert(main.begin(), pend.begin()->begin);
	pend.pop_front();

	for (int k = 2 ; ; ++k)
	{
		// Find next index
		std::size_t dist = utils::ft_calc_jacobsthal_diff(k);
		if (dist >= pend.size()) {
			break;
		}

		std::list<list_node>::iterator it = pend.begin();
		std::advance(it, dist - 1);

		while (true) {
			std::list<std::list<unsigned int>::iterator>::iterator insertion_point = binary_insert(main.begin(), it->pair_head, it->begin, num_comp);
			if (it->pair_head != main.end()) {
				main.insert(insertion_point, it->begin);
			}
			if (insertion_point != main.end()) {
				list.splice(*insertion_point, list, it->begin, ++(it->end));
			}
			else {
				list.splice(list.end(), list, it->begin, ++(it->end));
			}
			it = pend.erase(it);
			if (it == pend.begin()) {
				break;
			}
			--it;
		}
	}

	// If there are pend elements left, insert them too
	while (!pend.empty())
	{
		std::list<list_node>::iterator it = --(pend.end());
		std::list<std::list<unsigned int>::iterator>::iterator insertion_point = binary_insert(main.begin(), it->pair_head, it->begin, num_comp);
		if (it->pair_head != main.end()) {
			main.insert(insertion_point, it->begin);
		}
		if (insertion_point != main.end()) {
			list.splice(*insertion_point, list, it->begin, ++(it->end));
		}
		else {
			list.splice(list.end(), list, it->begin, ++(it->end));
		}
		pend.pop_back();
	}

}

std::size_t	ford_johnson_list(std::list<unsigned int>& list)
{
	std::size_t num_comp = 0;
	ford_johnson_list_impl(list, list.size(), 0, num_comp);
	return (num_comp);
}
