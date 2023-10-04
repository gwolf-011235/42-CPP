/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:07:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/04 10:25:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
bool 	bsp( Point const a, Point const b, Point const c, Point const p);
void	promptInput(float x[4], float y[4]);
void	init(int argc, char **argv);

Point *points[4];
bool	inside;

#include <iostream>

int main(int argc, char **argv)
{
	float x[4], y[4];
	promptInput(x, y);

	for(int i = 0; i < 4; ++i) {
		//delete points[i];
		points[i] = new Point(x[i], y[i]);
	}

	inside = bsp(*points[0], *points[1], *points[2], *points[3]);
	if (inside) {
			std::cout << "The point is inside the triangle.\n";
	} else {
			std::cout << "The point is outside the triangle.\n";
	}

	init(argc, argv);
	return 0;
}

