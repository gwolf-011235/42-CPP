/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:07:46 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/26 14:05:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type("Hands")
{
	std::cout << "Weapon Default constructor called\n";
}

Weapon::Weapon(const std::string& new_type) : type(new_type)
{
	std::cout << "Weapon Param constructor called\n";
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destructor called\n";
}

const std::string&	Weapon::getType(void) const
{
	return type;
}

void	Weapon::setType(const std::string& new_type)
{
	type = new_type;
}
