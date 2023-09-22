/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:09 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/22 14:32:10 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : m_value(0)
{
	std::cout << "Fixed default constructor called\n";
}

Fixed::Fixed(const Fixed& ref)
{
	std::cout << "Fixed copy constructor called\n";
	m_value = ref.m_value;
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	if (this == &ref)
		return *this;
	return *this(ref);
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed destructor called\n";
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "Fixed getRawBits member function called\n";
	return m_value;
}

void	Fixed::setRawBits( int const raw )
{
	m_value = raw;
}