/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/25 18:56:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	//std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

/*
int main( void )
{
	Fixed a( 21.21f );
	Fixed const b( 10 );
	Fixed const c( Fixed( 11.11f ) * Fixed( 22.22f ));
	Fixed const d( a / b );

	a = a + b;

	std::cout << "a smaller than b: " << (a < b) << std::endl;
	std::cout << "a bigger than b: " << (a > b) << std::endl;
	std::cout << "a smaller/equals b: " << (a <= b) << std::endl;
	std::cout << "a bigger/equals b: " << (a >= b) << std::endl;
	std::cout << "a equals b: " << (a == b) << std::endl;
	std::cout << "a does not equal b: " << (a != b) << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	return 0;
}
*/