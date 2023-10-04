/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:06:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/04 12:00:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

# define FRACTIONAL_BITS 8

class Fixed
{
private:
	int m_value;
	static const int s_fract_bits = FRACTIONAL_BITS;
public:
	Fixed(void);
	Fixed(const Fixed& ref);
	~Fixed(void);
	Fixed(const int);
	Fixed(const float);

	Fixed&	operator=(const Fixed& ref);

	bool	operator==(const Fixed& ref) const;
	bool	operator!=(const Fixed& ref) const;
	bool	operator<(const Fixed& ref) const;
	bool	operator>(const Fixed& ref) const;
	bool	operator<=(const Fixed& ref) const;
	bool	operator>=(const Fixed& ref) const;

	Fixed	operator+(const Fixed& ref) const;
	Fixed	operator-(const Fixed& ref) const;
	Fixed	operator/(const Fixed& ref) const;
	Fixed	operator*(const Fixed& ref) const;

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<< (std::ostream &out, Fixed const& f);