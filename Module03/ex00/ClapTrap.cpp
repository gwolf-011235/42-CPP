/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:22:39 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/06 09:04:51 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : m_name("unknown"), m_hit_points(10), m_energy_points(10), m_attack_damage(0)
{
	std::cout << "Default constructor called: ClapTrap \n";
}

ClapTrap::ClapTrap(const std::string& name) : m_name(name), m_hit_points(10), m_energy_points(10), m_attack_damage(0)
{
	std::cout << "Param constructor called: ClapTrap \n";
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
	std::cout << "Copy constructor called: ClapTrap \n";
	*this = ref;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
	if (&ref != this) {
		this->m_name = ref.getName();
		this->m_hit_points = ref.getHitPoints();
		this->m_energy_points = ref.getEnergyPoints();
		this->m_attack_damage = ref.getAttackDamage();
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called: ClapTrap \n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (!isFit(m_hit_points, m_energy_points, m_name, "attacks"))
		return ;
	std::cout << "ClapTrap " << m_name << " attacks " << target << " causing " << m_attack_damage << " points of damage!\n";
	m_energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage!\n";
	m_hit_points -= amount;
	if (m_hit_points < 0)
		m_hit_points = 0;
	if (!m_hit_points)
		std::cout << "ClapTrap " << m_name << " is incapacitated!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!isFit(m_hit_points, m_energy_points, m_name, "repair himself"))
		return ;
	std::cout << "ClapTrap " << m_name << " repairs " << amount << "points of damage!\n";
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

bool	ClapTrap::isFit(int hp, int ep, const std::string& name, const std::string& action)
{
	if (!hp || !ep) {
		std::cout << "ClapTrap" << name << " can't " << action << ": ";
		if (!hp)
			std::cout << "he dead.\n";
		else
			std::cout << "no energy left.\n";
		return false;
	}
	return true;
}