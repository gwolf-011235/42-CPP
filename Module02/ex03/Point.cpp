/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:19:47 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/28 17:56:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : m_x(0), m_y(0)
{
	std::cout << "Default constructor called: Point \n";
}

Point::Point(const float x, const float y): m_x(x), m_y(y)
{
	std::cout << "Float constructor called: Point \n";
}

Point::Point(const Point& ref) : m_x(ref.m_x), m_y(ref.m_y)
{
	std::cout << "Copy constructor called: Point \n";
}

Point& Point::operator=(const Point& ref)
{
	if (&ref != this) {
		std::cout << "Copy assignment called: Point - everything const oh no!\n";
	}
	return *this;
}

Point::~Point(void)
{
	std::cout << "Destructor called: Point \n";
}

float	Point::get_float_x() const
{
	return m_x.toFloat();
}

float	Point::get_float_y() const
{
	return m_y.toFloat();
}
