/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:17:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 15:57:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
HumanA::HumanA(void) : name("Nobody") weapon(NULL)
{
	std::cout << "HumanA Default constructor called\n";
}
*/

HumanB::HumanB(const std::string& new_name) : name(new_name), weapon(0)
{
	std::cout << "HumanB Param constructor called\n";
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB destructor called\n";
}

void	HumanB::attack(void)
{
	if (!weapon) {
		std::cout << name << " uses his fists" << std::endl;
	} else {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& new_weapon)
{
	weapon = &new_weapon;
}
