/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:57:03 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/11 15:51:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name", FragTrap::m_HP, ScavTrap::m_EP, FragTrap::m_AP), m_name(name)
{
	std::cout << "Default constructor called: DiamondTrap \n";
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
		ClapTrap::m_name = ref.ClapTrap::getName();
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

const std::string&	DiamondTrap::getName() const
{
	return m_name;
}

const std::string	DiamondTrap::getType() const
{
	return "DiamondTrap";
}

void	DiamondTrap::printStats() const
{
	std::cout << "*\t" << getType() << " " << m_name << " (" << ClapTrap::m_name << "):\t" << m_hit_points << " hp\t" << m_energy_points << " ep\t" << m_attack_damage << " ap\n";
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << m_name << " but I feel like a " << ClapTrap::m_name << "\n";
}
