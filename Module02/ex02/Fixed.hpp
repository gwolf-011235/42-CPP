/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:06:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/25 18:56:34 by gwolf            ###   ########.fr       */
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

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<< (std::ostream &out, Fixed const& f);