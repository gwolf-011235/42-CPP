/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:37:03 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/09 15:50:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* private stuff */
public:
	ScavTrap(const std::string& name = "ScaryBoi");
	ScavTrap(const ScavTrap& ref);
	~ScavTrap(void);
	ScavTrap& operator= (const ScavTrap& ref);

	const std::string	getType() const;

	void	attack(const std::string& target);
	void	guardGate();
};
