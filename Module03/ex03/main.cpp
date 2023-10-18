/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:22:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 23:30:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	testConstructDestruct(void)
{
	std::cout << "Test Default constructor - no param\n";
	DiamondTrap a;
	a.printStats();
	std::cout << "\n";

	std::cout << "Test Default constructor - with param\n";
	DiamondTrap b("gwolf");
	b.printStats();
	std::cout << "\n";

	std::cout << "Test Copy constructor - on second object\n";
	DiamondTrap c(b);
	c.printStats();
	std::cout << "\n";

	std::cout << "Test Copy assignment operator - on second object\n";
	DiamondTrap d;
	d = b;
	b.printStats();
	std::cout << "\n";

	std::cout << "Test Copy constructor of ClapTrap on first object\n";
	ClapTrap x(a);
	x.printStats();
	std::cout << "\n";
}

void	testCharacterMethods(void)
{
	DiamondTrap a("gwolf");
	DiamondTrap b("rruppi");

	a.attack(b.getName());
	a.printStats();
	a.takeDamage(4);
	a.printStats();
	a.beRepaired(4);
	a.printStats();
}

void	testIsDead(int health)
{
	DiamondTrap a("MrDead");

	a.takeDamage(health);
	a.printStats();
	a.attack("Somebody");
}

void	testNoEnergy(int energyPoints)
{
	DiamondTrap a("MrEnergy");

	for (int i = 0; i < energyPoints; ++i) {
		a.beRepaired(10);
		a.printStats();
	}
	a.beRepaired(10);
}

void	testSpecialMethods(void)
{
	DiamondTrap a("Special");

	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
}

int	main(void)
{
	testConstructDestruct();
	std::cout << "---------------\n";
	testCharacterMethods();
	std::cout << "---------------\n";
	testIsDead(100);
	std::cout << "---------------\n";
	testNoEnergy(50);
	std::cout << "---------------\n";
	testSpecialMethods();
}