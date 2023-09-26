/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:19:47 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/26 18:40:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : m_x(0), m_y(0), m_z(0)
{
	std::cout << "Default constructor called: Point \n";
}

Point::Point(const Point& ref)
{
	std::cout << "Copy constructor called: Point \n";
	*this = ref;
}

Point::Point( float x, float y, float z): m_x(x), m_y(y), m_z(z)
{
	std::cout << "Float constructor called: Point \n";
}

Point::Point( int x, int y, int z)
{
	std::cout << "Int constructor called: Point \n";

}

Point& Point::operator=(const Point& ref)
{
	if (&ref != this) {
		m_x = ref.m_x;
		m_y = ref.m_y;
		m_z = ref.m_z;
	}
	return *this;
}

Point::~Point(void)
{
	std::cout << "Destructor called: Point \n";
}
