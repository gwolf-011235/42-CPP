/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/04 10:30:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
bool 	bsp( Point const a, Point const b, Point const c, Point const p);

int main(void)
{
	Point a(0, 0);
	Point b(1, 1);
	Point c(1, 0);
	Point p(0.9, 0.5);

	std::cout << "Point a: (" << a.get_xf() << " " << a.get_yf() << ")\n";
	std::cout << "Point b: (" << b.get_xf() << " " << b.get_yf() << ")\n";
	std::cout << "Point c: (" << c.get_xf() << " " << c.get_yf() << ")\n";
	std::cout << "Point p: (" << p.get_xf() << " " << p.get_yf() << ")\n";

	if (bsp(a, b, c, p)) {
			std::cout << "The point is inside the triangle.\n";
	} else {
			std::cout << "The point is outside the triangle.\n";
	}

	return 0;
}

