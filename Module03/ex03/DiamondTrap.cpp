/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:57:03 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/09 16:25:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default constructor called: DiamondTrap \n";
	m_hit_points = FragTrap::getHitPoints();
	m_energy_points = ScavTrap::getEnergyPoints();
	m_attack_damage =  FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref)
{
	std::cout << "Copy constructor called: DiamondTrap \n";
	*this = ref;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref)
{
	std::cout << "Copy assignment operator called: DiamondTrap \n";
	if (&ref != this) {
		m_name = ref.getName();
		m_hit_points = ref.getHitPoints();
		m_energy_points = ref.getEnergyPoints();
		m_attack_damage = ref.getAttackDamage();
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor called: DiamondTrap \n";
}

const std::string	DiamondTrap::getType() const
{
	return "DiamondTrap";
}

void	DiamondTrap::whoAmI()
{

}
