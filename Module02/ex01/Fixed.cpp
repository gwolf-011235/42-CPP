/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:09 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/24 08:28:47 by gwolf            ###   ########.fr       */
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

Fixed::Fixed(int const num) : m_value(num << s_fract_bits)
{
	std::cout << "Int constructor called: Fixed\n";
}

Fixed::Fixed(float const num) : m_value(round(num * (1 << s_fract_bits)))
{
	std::cout << "Float constructor called: Fixed\n";
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

float	Fixed::toFloat( void ) const
{
	return ((float)m_value / (float)(1 << s_fract_bits));
}

int		Fixed::toInt( void ) const
{
	return m_value >> s_fract_bits;
}

std::ostream& operator<< (std::ostream &out, Fixed const& f)
{
	return out << f.toFloat();
}
