/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:19:19 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/02 08:47:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
	const Fixed m_x;
	const Fixed m_y;
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point& ref);
	Point& operator= (const Point& ref);
	~Point(void);
	float	get_xf() const;
	float	get_yf() const;
};

