/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:22:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/08 12:04:06 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string	m_name;
	int			m_hit_points;
	int 		m_energy_points;
	int			m_attack_damage;
public:
	ClapTrap(const std::string& name = "unkown");
	ClapTrap(const ClapTrap& ref);
	~ClapTrap(void);
	ClapTrap& operator= (const ClapTrap& ref);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	const std::string&	getName() const;
	int					getHitPoints() const;
	int 				getEnergyPoints() const;
	int					getAttackDamage() const;

	bool	isFit(const std::string& action) const;
	void	printStats() const;
};
