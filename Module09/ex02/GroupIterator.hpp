/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:07:39 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 10:42:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPITERATOR_HPP
# define GROUPITERATOR_HPP

#include <iterator>
#include <vector>

// Iterator used to bundle up elements of different sizes of the collection

class GroupIterator
{
	private:

		std::vector<unsigned int>::iterator m_it;
		std::size_t m_size;

	public:

		// Iterator traits

		typedef unsigned int 					value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef unsigned int*					pointer;
		typedef unsigned int&					reference;
		typedef std::bidirectional_iterator_tag	iterator_category;

		// Constructors

		GroupIterator();
		GroupIterator(std::vector<unsigned int>::iterator it, std::size_t size);
		GroupIterator(const GroupIterator& other);

		// Destructor

		~GroupIterator();

		// Assignment operator

		GroupIterator& operator=(const GroupIterator& other);

		// Members access

		std::vector<unsigned int>::iterator base() const;
		std::size_t size() const;

		// Element access

		reference operator*() const;

		// Increment/decrement operators

		GroupIterator& operator++();
		GroupIterator operator++(int);
		GroupIterator& operator--();
		GroupIterator operator--(int);
		GroupIterator& operator+=(std::size_t increment);
		GroupIterator& operator-=(std::size_t increment);
};

// Comparison operators

bool operator!=(const GroupIterator& lhs, const GroupIterator& rhs);
bool operator==(const GroupIterator& lhs, const GroupIterator& rhs);

// Construction functions

GroupIterator make_group_iterator(std::vector<unsigned int>::iterator it, std::size_t size);
GroupIterator make_group_iterator(GroupIterator it, std::size_t size);

// Utility functions

GroupIterator iter_prev(GroupIterator it, std::size_t n = 1);
GroupIterator iter_next(GroupIterator it, std::size_t n = 1);
void iter_swap(GroupIterator lhs, GroupIterator rhs);

#endif
