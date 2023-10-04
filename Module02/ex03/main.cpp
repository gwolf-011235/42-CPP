/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/04 12:11:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
bool 	bsp( Point const a, Point const b, Point const c, Point const p);

void	constructAndCheck(const float x[4], const float y[4])
{
	Point a(x[0], y[0]);
	Point b(x[1], y[1]);
	Point c(x[2], y[2]);
	Point p(x[3], y[3]);

	std::cout << "Point a: (" << a.get_xf() << " " << a.get_yf() << ")\n";
	std::cout << "Point b: (" << b.get_xf() << " " << b.get_yf() << ")\n";
	std::cout << "Point c: (" << c.get_xf() << " " << c.get_yf() << ")\n";
	std::cout << "Point p: (" << p.get_xf() << " " << p.get_yf() << ")\n\n";

	if (bsp(a, b, c, p)) {
			std::cout << "The point is inside the triangle.\n";
	} else {
			std::cout << "The point is outside the triangle.\n";
	}

	std::cout << std::endl;
}


int main(void)
{
	float x[4] = {0, 1, 1, 0};
	float y[4] = {0, 1, 0, 0};

	constructAndCheck(x, y);

	x[3] = 0.9;
	y[3] = 0.5;
	constructAndCheck(x, y);

	x[3] = 0.5;
	y[3] = 0.5;
	constructAndCheck(x, y);

	x[3] = 0.6;
	y[3] = 0.5;
	constructAndCheck(x, y);

	x[3] = 1;
	y[3] = 1;
	constructAndCheck(x, y);

	x[3] = 2;
	y[3] = 2;
	constructAndCheck(x, y);

	return 0;
}

