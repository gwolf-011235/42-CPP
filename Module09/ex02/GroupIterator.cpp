/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:38:18 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 11:04:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GroupIterator.hpp"

// Constructors

GroupIterator::GroupIterator()
{
}

GroupIterator::GroupIterator(std::vector<unsigned int>::iterator it, std::size_t size): m_it(it), m_size(size)
{
}

GroupIterator::GroupIterator(const GroupIterator& other): m_it(other.m_it), m_size(other.m_size)
{
}

// Destructor

GroupIterator::~GroupIterator()
{
}

// Assignment operator

GroupIterator& GroupIterator::operator=(const GroupIterator& other)
{
	m_it = other.m_it;
	m_size = other.m_size;
	return *this;
}

// Members access

std::vector<unsigned int>::iterator GroupIterator::base() const
{
	return m_it;
}

std::size_t GroupIterator::size() const
{
	return m_size;
}

// Element access

GroupIterator::reference GroupIterator::operator*() const
{
	return *m_it;
}

// Increment/decrement operators

GroupIterator& GroupIterator::operator++()
{
	m_it += m_size;
	return *this;
}

GroupIterator GroupIterator::operator++(int)
{
	GroupIterator tmp = *this;
	operator++();
	return tmp;
}

GroupIterator& GroupIterator::operator--()
{
	m_it -= m_size;
	return *this;
}

GroupIterator GroupIterator::operator--(int)
{
	GroupIterator tmp = *this;
	operator--();
	return tmp;
}

GroupIterator& GroupIterator::operator+=(std::size_t increment)
{
	m_it += m_size * increment;
	return *this;
}

GroupIterator& GroupIterator::operator-=(std::size_t increment)
{
	m_it -= m_size * increment;
	return *this;
}

// Comparison operators

bool operator==(const GroupIterator& lhs, const GroupIterator& rhs)
{
	return lhs.base() == rhs.base();
}

bool operator!=(const GroupIterator& lhs, const GroupIterator& rhs)
{
	return lhs.base() != rhs.base();
}

// Construction functions

GroupIterator make_GroupIterator(std::vector<unsigned int>::iterator it, std::size_t size)
{
	return GroupIterator(it, size);
}

GroupIterator make_GroupIterator(GroupIterator it, std::size_t size)
{
	return GroupIterator(it.base(), size * it.size());
}

// Utility functions

GroupIterator prev_GroupIterator(GroupIterator it, std::size_t n)
{
	std::advance(it, -n);
	return it;
}

GroupIterator next_GroupdIterator(GroupIterator it, std::size_t n)
{
	std::advance(it, n);
	return it;
}

void swap_GroupIterator(GroupIterator lhs, GroupIterator rhs)
{
	std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}
