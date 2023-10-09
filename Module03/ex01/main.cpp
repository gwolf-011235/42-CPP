/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:22:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/09 14:17:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("Stu");
	ScavTrap b("Lou");
	ScavTrap c(a);
	ScavTrap d = b;

	a.attack(b.getName());
	a.printStats();
	a.takeDamage(4);
	a.printStats();
	a.beRepaired(4);
	a.printStats();
	a.takeDamage(50);
	a.printStats();
	a.attack(b.getName());

	for (int i = 0; i < 50; ++i) {
		b.beRepaired(10);
		b.printStats();
	}
	b.beRepaired(10);
	c.guardGate();
}