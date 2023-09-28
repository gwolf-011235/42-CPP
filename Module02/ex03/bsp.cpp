/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:29:35 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/28 17:57:44 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	double denominator = (b.get_float_y() - c.get_float_y()) * (a.get_float_x() - c.get_float_x()) + (c.get_float_x())
}