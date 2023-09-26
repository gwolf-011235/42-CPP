/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:17:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/26 14:04:15 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void) : name("Nobody"), weapon(NULL)
{
	std::cout << "HumanB Default constructor called\n";
}

HumanB::HumanB(const std::string& new_name) : name(new_name), weapon(0)
{
	std::cout << "HumanB Param constructor called\n";
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB destructor called\n";
}

void	HumanB::attack(void) const
{
	if (!weapon) {
		std::cout << name << " attacks with their fists" << std::endl;
	} else {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon& new_weapon)
{
	weapon = &new_weapon;
}
