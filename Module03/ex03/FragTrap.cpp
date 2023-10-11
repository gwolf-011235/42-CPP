/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:03:47 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/11 14:13:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, m_HP, m_EP, m_AP)
{
	std::cout << "Default constructor called: FragTrap \n";
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
	std::cout << getType() << " " << m_name << " wants to give everybody a high five!\n";
}
