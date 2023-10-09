/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:37:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/09 11:31:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
{
	std::cout << "Default constructor called: ScavTrap \n";
	m_name = name;
	m_hit_points = 100;
	m_energy_points = 50;
	m_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& ref)
{
	std::cout << "Copy constructor called: ScavTrap \n";
	*this = ref;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
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
