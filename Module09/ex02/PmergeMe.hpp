/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/19 02:51:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>

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


}

#endif