/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:49:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 16:47:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	public:
		Array();
		Array(const unsigned int size);
		Array(const Array& src);
		~Array();
		Array&	operator=(const Array& src);
		T&		operator[](const unsigned int size);
		T&		operator[](const unsigned int size) const;
		unsigned int	size() const;
	private:
		T				*m_array;
		unsigned int	m_size;
};

# include "Array.tpp"

#endif
