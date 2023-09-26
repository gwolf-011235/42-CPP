/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/25 20:24:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a( 21.21f );
	Fixed const b( 10 );
	Fixed const c( Fixed( 11.11f ) * Fixed( 22.22f ));
	Fixed const d( a / b );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	a = a + b;

	std::cout << std::boolalpha;
	std::cout << "a smaller than b: " << (a < b) << std::endl;
	std::cout << "a bigger than b: " << (a > b) << std::endl;
	std::cout << "a smaller/equals b: " << (a <= b) << std::endl;
	std::cout << "a bigger/equals b: " << (a >= b) << std::endl;
	std::cout << "a equals b: " << (a == b) << std::endl;
	std::cout << "a does not equal b: " << (a != b) << std::endl;


	std::cout << "Fixed a: " << a << std::endl;
	std::cout << "Pre increment: " << ++a << std::endl;
	std::cout << "Fixed a: " << a << std::endl;
	std::cout << "Post increment: " << a++ << std::endl;

	std::cout << "Fixed a: " << a << std::endl;
	std::cout << "Fixed b: " << b << std::endl;
	std::cout << "Max between a and b: " << Fixed::max( a, b ) << std::endl;
	std::cout << "Fixed c: " << c << std::endl;
	std::cout << "Fixed d: " << d << std::endl;
	std::cout << "Min between c and d: " << Fixed::min( c, d ) << std::endl;

	return 0;
}