/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:09 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/22 14:47:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : m_value(0)
{
	std::cout << "Default constructor called: Fixed\n";
}

Fixed::Fixed(const Fixed& ref)
{
	std::cout << "Copy constructor called: Fixed\n";
	*this = ref;
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	if (&ref != this) {
		this->m_value = ref.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called: Fixed\n";
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called: Fixed\n";
	return m_value;
}

void	Fixed::setRawBits( int const raw )
{
	m_value = raw;
}