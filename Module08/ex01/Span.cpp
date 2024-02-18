/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:10:09 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/18 19:26:10 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : m_numbers(), m_size(0), m_count(0)
{
}

Span::Span(const unsigned int N) : m_numbers(N), m_size(N), m_count(0)
{
}

Span::Span(const Span& src) : m_numbers(src.m_numbers), m_size(src.m_size), m_count(src.m_count)
{
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& src)
{
	if (this == &src)
		return *this;
	m_numbers = src.m_numbers;
	m_size = src.m_size;
	m_count = src.m_count;
	return *this;
}

void	Span::addNumber(const int number)
{
	if (m_count >= m_size)
		throw std::out_of_range("Span is full");
	std::vector<int>::iterator it = std::lower_bound(m_numbers.begin(), m_numbers.begin() + m_count, number);
	m_numbers.insert(it, number);
	m_count++;
}

int	Span::shortestSpan() const
{
	if (m_count < 2)
		throw std::out_of_range("Span is too short");
	std::vector<int>::const_iterator it = m_numbers.begin();
	int	span = *(it + 1) - *it;
	for (; it != m_numbers.begin() + m_count - 1; ++it)
	{
		int diff = *(it + 1) - *it;
		if (diff < span)
			span = diff;
	}
	return span;
}

int	Span::longestSpan() const
{
	if (m_count < 2)
		throw std::out_of_range("Span is too short");
	std::vector<int>::const_iterator it_min = m_numbers.begin();
	std::vector<int>::const_iterator it_max = m_numbers.begin() + m_count - 1;
	return *it_max - *it_min;
}

void	Span::print() const
{
	std::cout << "Span contents: ";
	std::copy(m_numbers.begin(), m_numbers.begin() + m_count, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
