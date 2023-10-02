/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/02 11:30:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);
void	promptInput(float x[4], float y[4]);
void	init(int argc, char **argv);

Point* a;
Point* b;
Point* c;
Point* p;
bool	inside;

#include <iostream>

int main(int argc, char **argv)
{
	float x[4], y[4];
	promptInput(x, y);

	a = new Point(x[0], y[0]);
	b = new Point(x[1], y[1]);
	c = new Point(x[2], y[2]);
	p = new Point(x[3], y[3]);

	inside = bsp(*a, *b, *c, *p);
	if (inside) {
			std::cout << "The point is inside the triangle.\n";
	} else {
			std::cout << "The point is outside the triangle.\n";
	}

	init(argc, argv);
	delete a;
	delete b;
	delete c;
	delete p;
	return 0;
}

