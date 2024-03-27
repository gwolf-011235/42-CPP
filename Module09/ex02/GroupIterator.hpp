/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:07:39 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/27 15:31:18 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPITERATOR_HPP
# define GROUPITERATOR_HPP

#include <iterator>
#include <vector>

////////////////////////////////////////////////////////////
// Iterator used to sort views of the collection

class group_iterator
{
	private:

		std::vector<int>::iterator m_it;
		std::size_t m_size;

	public:

		////////////////////////////////////////////////////////////
		// Iterator traits

		typedef int 							value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef int*							pointer;
		typedef int&							reference;
		typedef std::bidirectional_iterator_tag	iterator_category;

		////////////////////////////////////////////////////////////
		// Constructors

		group_iterator()
		{

		};

		group_iterator(std::vector<int>::iterator it, std::size_t size): m_it(it), m_size(size)
		{

		}

		////////////////////////////////////////////////////////////
		// Members access

		std::vector<int>::iterator base() const
		{
			return m_it;
		}

		std::size_t size() const
		{
			return m_size;
		}

		////////////////////////////////////////////////////////////
		// Element access

		reference operator*() const
		{
			return *m_it;
		}

		////////////////////////////////////////////////////////////
		// Increment/decrement operators

		group_iterator& operator++()
		{
			m_it += m_size;
			return *this;
		}

		group_iterator operator++(int)
		{
			group_iterator tmp = *this;
			operator++();
			return tmp;
		}

		group_iterator& operator--()
		{
			m_it -= m_size;
			return *this;
		}

		group_iterator operator--(int)
		{
			group_iterator tmp = *this;
			operator--();
			return tmp;
		}

		group_iterator& operator+=(std::size_t increment)
		{
			m_it += m_size * increment;
			return *this;
		}

		group_iterator& operator-=(std::size_t increment)
		{
			m_it -= m_size * increment;
			return *this;
		}

};

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

////////////////////////////////////////////////////////////
// Construction function

group_iterator make_group_iterator(std::vector<int>::iterator it, std::size_t size)
{
	return group_iterator(it, size);
}

group_iterator make_group_iterator(group_iterator it, std::size_t size)
{
	return group_iterator(it.base(), size * it.size());
}

group_iterator iter_prev(group_iterator it, std::size_t n = 1)
{
	std::advance(it, -n);
	return it;
}

group_iterator iter_next(group_iterator it, std::size_t n = 1)
{
	std::advance(it, n);
	return it;
}

#endif
