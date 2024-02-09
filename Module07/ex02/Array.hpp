/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:49:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/09 19:32:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int size);
		Array(Array const &src);
		~Array();
		Array	&operator=(Array const &src);
		T		&operator[](unsigned int size);
		unsigned int	size() const;
		void			printArray() const;
	private:
		T				*m_array;
		unsigned int	m_size;
};

# include "Array.tpp"

#endif
