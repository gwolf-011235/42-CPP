/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/23 21:56:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <utility>
# include <algorithm>

void	ft_merge(std::vector<int>::iterator begin, std::vector<int>::iterator mid, std::vector<int>::iterator end)
{
	int i, j;
	int n1 = std::distance(begin, mid);
	int n2 = std::distance(mid, end);
	std::vector<int>::iterator it = begin;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (i = 0; begin != mid; ++i, ++begin) {
		L[i] = *begin;
	}
	for (j = 0; mid != end; ++j, ++mid) {
		R[j] = *mid;
	}
	i = 0;
	j = 0;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			*it = L[i];
			i++;
			it++;
			*it = L[i];
			i++;
		} else {
			*it = R[j];
			j++;
			it++;
			*it = R[j];
			j++;
		}
		it++;
	}
	while (i < n1) {
		*it = L[i];
		i++;
		it++;
	}
	while (j < n2) {
		*it = R[j];
		j++;
		it++;
	}
}

void	ft_mergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (begin + 2 < end) {
		std::vector<int>::iterator mid = begin;
		size_t count_of_pairs = std::distance(begin, end) / 2;
		if (count_of_pairs % 2) {
			count_of_pairs++;
		}
		std::advance(mid, count_of_pairs);
		ft_mergeSort(begin, mid);
		ft_mergeSort(mid, end);
		ft_merge(begin, mid, end);
	}
}

void	ft_sortPairs(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (; begin < end; begin += 2) {
		if (*begin < *(begin + 1)) {
			std::iter_swap(begin, begin + 1);
		}
	}
}

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

bool	compare_iters(const std::vector<int>::iterator value, const std::vector<int>::iterator iter)
{
	return (*value < *iter);
}

void	ft_sortMainPendChain(std::vector<int>::iterator begin, std::vector<int>::iterator end, const bool has_stray)
{
	std::list<std::vector<int>::iterator> main;
	std::list<std::pair<std::vector<int>::iterator, std::list<std::vector<int>::iterator>::iterator> > pend;

	main.insert(main.end(), begin + 1);
	main.insert(main.end(), begin);

	for (std::vector<int>::iterator it = begin + 2; it != end; ++it) {
		std::list<std::vector<int>::iterator>::iterator tmp = main.insert(main.end(), it);
		++it;
		pend.push_back(std::make_pair(it, tmp));
	}

	if (has_stray) {
		pend.push_back(std::make_pair(end, main.end()));
	}

	for (size_t insertion_step = 1; ; ++insertion_step) {
		size_t dist = ft_calc_jacobsthal_diff(insertion_step);
		if (dist > pend.size()) {
			break;
		}
		std::list<std::pair<std::vector<int>::iterator, std::list<std::vector<int>::iterator>::iterator> >::iterator it = pend.begin();
		std::advance(it, dist);

		while (true) {
			std::list<std::vector<int>::iterator>::iterator insertion_point = std::upper_bound(main.begin(), it->second, it->first, compare_iters);

			main.insert(insertion_point, it->first);

			it = pend.erase(it);
			if (it == pend.begin())
				break;
			--it;
		}

		while (!pend.empty()) {
			std::list<std::pair<std::vector<int>::iterator, std::list<std::vector<int>::iterator>::iterator> >::iterator it = pend.end();
			--it;

			std::list<std::vector<int>::iterator>::iterator insertion_point = std::upper_bound(main.begin(), it->second, it->first, compare_iters);
			main.insert(insertion_point, it->first);
			pend.pop_back();
		}

		std::list<std::vector<int>::iterator>::iterator start = main.begin();
		std::list<std::vector<int>::iterator>::iterator end = main.end();

		for (; start != end; ++start) {
			std::cout << **start << "-";
		}
		std::cout << "\n";


	}



}

void	ft_FordJohnsonVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	ft_printVector("Starting point: ", begin, end);
	size_t size = std::distance(begin, end);
	bool has_stray = size % 2;
	if (has_stray) {
		end--;
	}
	ft_sortPairs(begin, end);
	ft_printVector("After pair sort: ", begin, end);
	ft_mergeSort(begin, end);
	ft_printVector("After merge sort: ", begin, end);
	ft_sortMainPendChain(begin, end, has_stray);


}

#endif