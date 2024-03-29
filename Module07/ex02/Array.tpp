/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:56:29 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 16:47:59 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# ifndef ARRAY_HPP
#  error "This file should only be included by Array.hpp"
# endif

# include <iostream>

template <typename T>
Array<T>::Array() : m_array(NULL), m_size(0)
{
	std::cout << "Array default constructor called: empty\n";
}

template <typename T>
Array<T>::Array(const unsigned int size) : m_array(new T[size]()), m_size(size)
{
	std::cout << "Array constructor called: " << size << " elements\n";
}

template <typename T>
Array<T>::Array(const Array& src) : m_array(new T[src.m_size]()), m_size(src.m_size)
{
	std::cout << "Array copy constructor called: " << m_size << " elements\n";
	for (unsigned int i = 0; i < m_size; ++i)
		m_array[i] = src.m_array[i];
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called: " << m_size << " elements\n";
	delete[] m_array;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& src)
{
	std::cout << "Array assignment operator called: " << src.m_size << " elements\n";
	if (this == &src)
		return *this;
	delete[] m_array;
	m_array = new T[src.m_size]();
	m_size = src.m_size;
	for (unsigned int i = 0; i < m_size; ++i)
		m_array[i] = src.m_array[i];
	return *this;
}

template <typename T>
T&	Array<T>::operator[](const unsigned int index)
{
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return m_array[index];
}

template <typename T>
T&	Array<T>::operator[](const unsigned int index) const
{
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return m_array[index];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return m_size;
}

#endif
