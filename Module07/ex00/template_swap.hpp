/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_swap.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:15:47 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/07 17:18:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_SWAP_HPP
# define TEMPLATE_SWAP_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

#endif
