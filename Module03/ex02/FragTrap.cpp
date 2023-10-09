/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:03:47 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/09 15:18:19 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
{
	std::cout << "Default constructor called: FragTrap \n";
	m_name = name;
	m_hit_points = 100;
	m_energy_points = 100;
	m_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& ref)
{
	std::cout << "Copy constructor called: FragTrap \n";
	*this = ref;
}

FragTrap& FragTrap::operator=(const FragTrap& ref)
{
	std::cout << "Copy assignment operator called: FragTrap \n";
	if (&ref != this) {
		m_name = ref.getName();
		m_hit_points = ref.getHitPoints();
		m_energy_points = ref.getEnergyPoints();
		m_attack_damage = ref.getAttackDamage();
	}
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called: FragTrap \n";
}

const std::string	FragTrap::getType() const
{
	return "FragTrap";
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << getType() << " " << m_name << " is ready for a high five!\n";
}
