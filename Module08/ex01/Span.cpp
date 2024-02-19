/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 08:10:09 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/19 10:31:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : m_numbers(), m_size(0), m_count(0)
{
}

// The vector is initialized with N elements of value 0 to avoid resizing.
// m_count is used to keep track of the number of elements in the vector.
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
		throw std::out_of_range("Cannot add number: Span is full");
	std::vector<int>::iterator it = std::lower_bound(m_numbers.begin(), m_numbers.begin() + m_count, number);
	m_numbers.insert(it, number);
	m_count++;
}

// Calc the span of the first pair and then iterate through the vector to find the shortest span.
// The vector is sorted so subtract the next element from the current one.
// Only iterate up to m_count - 2: the last pair consists of the element before the last one and the last one.
int	Span::shortestSpan() const
{
	if (m_count < 2)
		throw std::out_of_range("Span has not enough elements");
	std::vector<int>::const_iterator it = m_numbers.begin();
	int	span = *(it + 1) - *it;
	it++;
	for (; it != m_numbers.begin() + m_count - 2; ++it)
	{
		int diff = *(it + 1) - *it;
		if (diff < span)
			span = diff;
	}
	return span;
}

// since vector is sorted take the first and last element.
// m_count needs to be reduced by 1 to get an iterator on the last element.
int	Span::longestSpan() const
{
	if (m_count < 2)
		throw std::out_of_range("Span has not enough elements");
	std::vector<int>::const_iterator it_min = m_numbers.begin();
	std::vector<int>::const_iterator it_max = m_numbers.begin() + m_count - 1;
	return *it_max - *it_min;
}

void	Span::print() const
{
	std::cout << "Span contents: ";
	if (m_count == 0)
		std::cout << "empty";
	else
		std::copy(m_numbers.begin(), m_numbers.begin() + m_count, std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}
