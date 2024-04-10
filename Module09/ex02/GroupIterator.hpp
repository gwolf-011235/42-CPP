/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:07:39 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/10 13:40:36 by gwolf            ###   ########.fr       */
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

		std::vector<unsigned int>::iterator m_it;
		std::size_t m_size;

	public:

		////////////////////////////////////////////////////////////
		// Iterator traits

		typedef unsigned int 					value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef unsigned int*					pointer;
		typedef unsigned int&					reference;
		typedef std::bidirectional_iterator_tag	iterator_category;

		////////////////////////////////////////////////////////////
		// Constructors

		group_iterator();

		group_iterator(std::vector<unsigned int>::iterator it, std::size_t size);

		group_iterator(const group_iterator& other);

		// Destructor
		~group_iterator();

		// Assignment operator

		group_iterator& operator=(const group_iterator& other);

		// Members access

		std::vector<unsigned int>::iterator base() const;

		std::size_t size() const;

		////////////////////////////////////////////////////////////
		// Element access

		reference operator*() const;

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


////////////////////////////////////////////////////////////
// Comparison operators

bool operator==(const group_iterator& lhs, const group_iterator& rhs);

bool operator!=(const group_iterator& lhs, const group_iterator& rhs);

group_iterator make_group_iterator(std::vector<unsigned int>::iterator it, std::size_t size);
group_iterator make_group_iterator(group_iterator it, std::size_t size);

////////////////////////////////////////////////////////////
// Utility functions

group_iterator iter_prev(group_iterator it, std::size_t n = 1);

group_iterator iter_next(group_iterator it, std::size_t n = 1);

void iter_swap(group_iterator lhs, group_iterator rhs);

#endif
