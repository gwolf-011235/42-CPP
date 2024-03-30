/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupdIterator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:38:18 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/30 11:48:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GroupIterator.hpp"

// Constructors

group_iterator::group_iterator()
{

}

group_iterator::group_iterator(std::vector<int>::iterator it, std::size_t size): m_it(it), m_size(size)
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

std::vector<int>::iterator group_iterator::base() const
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

