/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:49:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/18 19:25:05 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
	public:
		Span();
		Span(const unsigned int N);
		Span(const Span& src);
		~Span();
		Span&	operator=(const Span& src);
		void	addNumber(const int number);
		template <typename InputIt> void addNumber(InputIt first, InputIt last);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	print() const;
	private:
		std::vector<int>	m_numbers;
		unsigned int		m_size;
		unsigned int		m_count;
};

# include "Span.tpp"

#endif
