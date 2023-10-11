/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:22:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/11 15:50:37 by gwolf            ###   ########.fr       */
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
	ClapTrap(const std::string& name = "NormalBoi");
	ClapTrap(const std::string& name, int hp, int ep, int ap);
	ClapTrap(const ClapTrap& ref);
	~ClapTrap(void);
	ClapTrap& operator= (const ClapTrap& ref);

	virtual void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	virtual const std::string&	getName() const;
	int					getHitPoints() const;
	int 				getEnergyPoints() const;
	int					getAttackDamage() const;
	virtual const std::string	getType() const;

	bool	isFit(const std::string& action) const;
	virtual void	printStats() const;
};
