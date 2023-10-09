/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:22:39 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/09 14:33:00 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : m_name(name), m_hit_points(10), m_energy_points(10), m_attack_damage(0)
{
	std::cout << "Default constructor called: ClapTrap \n";
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
	std::cout << "Copy constructor called: ClapTrap \n";
	*this = ref;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
	if (&ref != this) {
		m_name = ref.getName();
		m_hit_points = ref.getHitPoints();
		m_energy_points = ref.getEnergyPoints();
		m_attack_damage = ref.getAttackDamage();
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called: ClapTrap \n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (!isFit("attack"))
		return ;
	std::cout << "ClapTrap " << m_name << " attacks " << target << " causing " << m_attack_damage << " points of damage!\n";
	m_energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << getType() << " " << m_name << " takes " << amount << " points of damage!\n";
	m_hit_points -= amount;
	if (m_hit_points < 0)
		m_hit_points = 0;
	if (!m_hit_points)
		std::cout << "ClapTrap " << m_name << " is incapacitated!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!isFit("repair himself"))
		return ;
	std::cout << getType() << " " << m_name << " repairs " << amount << " points of damage!\n";
	m_hit_points += amount;
	m_energy_points--;
}

const std::string&	ClapTrap::getName() const
{
	return m_name;
}

int			ClapTrap::getHitPoints() const
{
	return m_hit_points;
}

int 		ClapTrap::getEnergyPoints() const
{
	return m_energy_points;
}

int			ClapTrap::getAttackDamage() const
{
	return m_attack_damage;
}

const std::string	ClapTrap::getType() const
{
	return "ClapTrap";
}

bool	ClapTrap::isFit(const std::string& action) const
{
	if (!m_hit_points || !m_energy_points) {
		std::cout << getType() << " " << m_name << " can't " << action << ": ";
		if (!m_hit_points)
			std::cout << "he dead.\n";
		else
			std::cout << "no energy left.\n";
		return false;
	}
	return true;
}

void	ClapTrap::printStats() const
{
	std::cout << "*\t" << getType() << " " << m_name << ":\t" << m_hit_points << " hp\t" << m_energy_points << " energy\n";
}