/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:22:39 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/18 19:26:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
# define SPAN_TPP

# ifndef SPAN_HPP
#  error "This file should only be included by Span.hpp"
# endif

template <typename InputIt>
void	Span::addNumber(InputIt first, InputIt last)
{
	unsigned int size = std::distance(first, last);
	if (m_count + size > m_size)
		throw std::out_of_range("Span is full");
	for (InputIt it = first; it != last; ++it)
		addNumber(*it);
}

#endif
