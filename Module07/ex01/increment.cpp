/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:00:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 16:08:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Data.hpp"

void	increment(int &x)
{
	x++;
}

void	increment(float &x)
{
	x += 0.5;
}

void	increment(double &x)
{
	x += 0.3;
}

void	increment(std::string &x)
{
	x += "!";
}

void	increment(Data &x)
{
	x.count += 100;
}
