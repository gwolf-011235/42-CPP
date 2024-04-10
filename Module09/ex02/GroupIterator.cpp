/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:38:18 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/10 13:40:54 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GroupIterator.hpp"

// Constructors

group_iterator::group_iterator()
{

}

group_iterator::group_iterator(std::vector<unsigned int>::iterator it, std::size_t size): m_it(it), m_size(size)
{

}

group_iterator::group_iterator(const group_iterator& other): m_it(other.m_it), m_size(other.m_size)
{

}

// Destructor

group_iterator::~group_iterator()
{

}

// Operators

group_iterator& group_iterator::operator=(const group_iterator& other)
{
	m_it = other.m_it;
	m_size = other.m_size;
	return *this;
}

// Members access

std::vector<unsigned int>::iterator group_iterator::base() const
{
	return m_it;
}

std::size_t group_iterator::size() const
{
	return m_size;
}

// Element access

group_iterator::reference group_iterator::operator*() const
{
	return *m_it;
}

////////////////////////////////////////////////////////////
// Construction function

group_iterator make_group_iterator(std::vector<unsigned int>::iterator it, std::size_t size)
{
	return group_iterator(it, size);
}

group_iterator make_group_iterator(group_iterator it, std::size_t size)
{
	return group_iterator(it.base(), size * it.size());
}

////////////////////////////////////////////////////////////
// Utility functions

group_iterator iter_prev(group_iterator it, std::size_t n)
{
	std::advance(it, -n);
	return it;
}

group_iterator iter_next(group_iterator it, std::size_t n)
{
	std::advance(it, n);
	return it;
}

void iter_swap(group_iterator lhs, group_iterator rhs)
{
	std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}

////////////////////////////////////////////////////////////
// Comparison operators

bool operator==(const group_iterator& lhs, const group_iterator& rhs)
{
	return lhs.base() == rhs.base();
}

bool operator!=(const group_iterator& lhs, const group_iterator& rhs)
{
	return lhs.base() != rhs.base();
}
