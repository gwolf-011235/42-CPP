/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:17:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 15:49:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
HumanA::HumanA(void) : name("Nobody") weapon(NULL)
{
	std::cout << "HumanA Default constructor called\n";
}
*/

HumanA::HumanA(const std::string& new_name, Weapon& new_weapon) : name(new_name), weapon(new_weapon)
{
	std::cout << "HumanA Param constructor called\n";
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA destructor called\n";
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
