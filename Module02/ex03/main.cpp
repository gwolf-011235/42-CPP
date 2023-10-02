/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/02 09:35:15 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);
int promptInput(void);

#include <iostream>
#include <limits> // For numeric_limits

int main( void )
{
	Point a(0.0, 0.0);
	Point b(1.0, 0.0);
	Point c(0.5, 1.0);

	Point x(0.5, 0.5);

	promptInput();
	if (bsp(a, b, c, x)) {
			std::cout << "The point is inside the triangle.\n";
	} else {
			std::cout << "The point is outside the triangle.\n";
	}
	return 0;
}

