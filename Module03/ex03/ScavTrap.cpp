/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:37:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/11 15:57:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, m_HP, m_EP, m_AP)
{
	std::cout << "Default constructor called: ScavTrap \n";
}

ScavTrap::ScavTrap(const ScavTrap& ref)
{
	std::cout << "Copy constructor called: ScavTrap \n";
	*this = ref;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
	std::cout << "Copy assignment operator called: ScavTrap \n";
	if (&ref != this) {
		m_name = ref.getName();
		m_hit_points = ref.getHitPoints();
		m_energy_points = ref.getEnergyPoints();
		m_attack_damage = ref.getAttackDamage();
	}
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called: ScavTrap \n";
}

const std::string	ScavTrap::getType() const
{
	return "ScavTrap";
}

void	ScavTrap::attack(const std::string& target)
{
	if (!isFit("attack"))
		return ;
	std::cout << getType() << " " << m_name << " ravages " << target << " causing " << m_attack_damage << " points of damage!\n";
	m_energy_points--;
}

void	ScavTrap::guardGate()
{
	if (!isFit("gatekeeper mode"))
		return ;
	std::cout << getType() << " " << m_name << " is now in gatekeeper mode.\n";
	m_energy_points--;
}