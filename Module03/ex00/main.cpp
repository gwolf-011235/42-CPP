/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:22:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/06 13:43:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Bud");
	ClapTrap b("Terence");
	ClapTrap c(a);
	ClapTrap d = b;

	a.attack(b.getName());
	std::cout << "ClapTrap " << a.getName() << " has " << a.getEnergyPoints() << " energy left.\n";
	a.takeDamage(4);
	std::cout << "ClapTrap " << a.getName() << " has " << a.getHitPoints() << " hit points left.\n";
	a.beRepaired(4);
	std::cout << "ClapTrap " << a.getName() << " has " << a.getHitPoints() << " hit points left.\n";
	std::cout << "ClapTrap " << a.getName() << " has " << a.getEnergyPoints() << " energy left.\n";
	a.takeDamage(50);
	a.attack(b.getName());
	for (int i = 0; i < 10; ++i) {
		b.beRepaired(10);
	}
	b.beRepaired(10);
}