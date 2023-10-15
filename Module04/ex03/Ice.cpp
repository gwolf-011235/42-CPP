/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:30:48 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 21:31:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	std::cout << "Default constructor called: Ice \n";
}

Ice::Ice(const Ice& ref)
{
	std::cout << "Copy constructor called: Ice \n";
}

Ice& Ice::operator=(const Ice& ref)
{
	std::cout << "Copy assignment operator called: Ice \n";
}

Ice::~Ice(void)
{
	std::cout << "Destructor called: Ice \n";
}
