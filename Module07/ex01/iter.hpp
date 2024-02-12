/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:23:43 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 15:42:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template< typename T >
void	iter(T *array, const size_t length, void (* const f)(const T &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template< typename T >
void	iter(T *array, const size_t length, void (* const f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif
