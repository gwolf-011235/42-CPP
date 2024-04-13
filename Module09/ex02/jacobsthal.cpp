/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:08:35 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 11:14:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ford_johnson.hpp"

std::size_t	calc_jacobsthal_num(std::size_t n)
{
	// base case
	if (n == 0)
		return 0;

	// base case
	if (n == 1)
		return 1;

	// recursive step.
	return calc_jacobsthal_num(n - 1) + 2 * calc_jacobsthal_num(n - 2);
}

std::size_t	calc_diff_jacobsthal_num(std::size_t n)
{
	return calc_jacobsthal_num(n + 1) - calc_jacobsthal_num(n);
}
