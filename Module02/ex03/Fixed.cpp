/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:09 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/25 18:56:45gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : m_value(0)
{
	//std::cout << "Default constructor called: Fixed\n";
}

Fixed::Fixed(const Fixed& ref)
{
	//std::cout << "Copy constructor called: Fixed\n";
	*this = ref;
}


Fixed::Fixed(int const num) : m_value(num << s_fract_bits)
{
	//std::cout << "Int constructor called: Fixed\n";
}

Fixed::Fixed(float const num) : m_value(roundf(num * (1 << s_fract_bits)))
{
	//std::cout << "Float constructor called: Fixed\n";
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called: Fixed\n";
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	if (&ref != this) {
		this->m_value = ref.getRawBits();
	}
	return *this;
}

bool	Fixed::operator==(const Fixed& ref) const
{
	return this->getRawBits() == ref.getRawBits();
}

bool	Fixed::operator!=(const Fixed& ref) const
{
	return !(*this == ref);
}

bool	Fixed::operator<(const Fixed& ref) const
{
	return this->getRawBits() < ref.getRawBits();
}

bool	Fixed::operator>(const Fixed& ref) const
{
	return ref < *this;
}

bool	Fixed::operator<=(const Fixed& ref) const
{
	return !(*this > ref);
}

bool	Fixed::operator>=(const Fixed& ref) const
{
	return !(*this < ref);
}

Fixed	Fixed::operator+(const Fixed& ref) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + ref.getRawBits());
	return tmp;
}

Fixed	Fixed::operator-(const Fixed& ref) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - ref.getRawBits());
	return tmp;
}

Fixed	Fixed::operator/(const Fixed& ref) const
{
	return Fixed( (float) ( (double)this->getRawBits() / (double)ref.getRawBits() ) );
}

Fixed	Fixed::operator*(const Fixed& ref) const
{
	long tmp = this->getRawBits() * ref.getRawBits();
	float tmp2 = (double)tmp / (double) ((1 << s_fract_bits));
	tmp2 /= (double) ((1 << s_fract_bits));
	return Fixed(tmp2);
}

Fixed&	Fixed::operator++()
{
	m_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits());
	operator++();
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	//std::cout << "normal min method\n";
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	//std::cout << "const min method\n";
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	//std::cout << "normal max method\n";
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	//std::cout << "const max method\n";
	return (a > b ? a : b);
}

int		Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called: Fixed\n";
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
