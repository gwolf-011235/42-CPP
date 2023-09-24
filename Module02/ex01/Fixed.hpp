/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:06:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/24 08:27:42 by gwolf            ###   ########.fr       */
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
	Fixed& operator= (const Fixed& ref);
	Fixed(const int);
	Fixed(const float);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<< (std::ostream &out, Fixed const& f);