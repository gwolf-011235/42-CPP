/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/11 12:51:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>

void	ft_merge(std::vector<int> &vec, int begin, int mid, int end)
{
	int i, j, k;
	int n1 = mid - begin + 1;
	int n2 = end - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (i = 0; i < n1; i++) {
		L[i] = vec[begin + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = vec[mid + 1 + j];
	}
	i = 0;
	j = 0;
	k = begin;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vec[k] = L[i];
			i++;
		} else {
			vec[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		vec[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		vec[k] = R[j];
		j++;
		k++;
	}
}

void	ft_mergeSort(std::vector<int> &vec, int begin, int end)
{
	if (begin < end) {
		int mid = begin + (end - begin) / 2;
		ft_mergeSort(vec, begin, mid);
		ft_mergeSort(vec, mid + 1, end);
		ft_merge(vec, begin, mid, end);
	}
}

void	ft_FordJohnsonVector(std::vector<int> &vec)
{
	bool has_stray = vec.size() % 2;

	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	if (has_stray) {
		ite--;
	}
	for (; it != ite; it += 2) {
		if (*it > *(it + 1)) {
			std::iter_swap(it, it + 1);
		}
	}

}

#endif