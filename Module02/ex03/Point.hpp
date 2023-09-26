/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:19:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/26 17:43:59 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
	Fixed m_x, m_y, m_z;
public:
	Point(void);
	Point(const Point& ref);
	~Point(void);
	Point& operator= (const Point& ref);
	Point( float x, float y, float z);
	Point( int x, int y, int z);
};

