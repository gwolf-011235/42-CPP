/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:06:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/22 14:31:00 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
	int m_value;
	static const int s_fract_bits = 8;
public:
	Fixed(void);
	Fixed(const Fixed& ref);
	~Fixed(void);
	Fixed& operator= (const Fixed& ref);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
