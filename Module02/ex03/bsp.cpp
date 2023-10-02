/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:29:35 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/02 08:51:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	double denominator = (b.get_yf() - c.get_yf()) * (a.get_xf() - c.get_xf()) + (c.get_xf()) * (a.get_yf() - c.get_yf());
	double lambda1 = ((b.get_yf() - c.get_yf()) * (point.get_xf() - c.get_xf()) + (c.get_xf() - b.get_xf()) * (point.get_yf() - c.get_yf())) / denominator;
	double lambda2 = ((c.get_yf() - a.get_yf()) * (point.get_xf() - c.get_xf()) + (a.get_xf() - c.get_xf()) * (point.get_yf() - c.get_yf())) / denominator;
	double lambda3 = 1.0 - lambda1 - lambda2;

	return (lambda1 >= 0.0 && lambda1 <= 1.0 &&
			lambda2 >= 0.0 && lambda2 <= 1.0 &&
			lambda3 >= 0.0 && lambda3 <= 1.0);
}