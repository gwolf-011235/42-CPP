/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:55:40 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/06 11:05:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const &copy) : std::stack<T>(copy) {}
	~MutantStack() {}

	MutantStack &operator=(MutantStack const &copy)
	{
		if (this == &copy)
			return *this;
		std::stack<T>::operator=(copy);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	iterator begin() { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }
	const_iterator cbegin() const { return std::stack<T>::c.begin(); }
	const_iterator cend() const { return std::stack<T>::c.end(); }
};

#endif
