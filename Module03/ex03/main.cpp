/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:22:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/09 16:19:52 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	testConstructDestruct(void)
{
	std::cout << "Test Default constructor - no param\n";
	FragTrap a;
	a.printStats();
	std::cout << "\n";

	std::cout << "Test Default constructor - with param\n";
	FragTrap b("Lou");
	b.printStats();
	std::cout << "\n";

	std::cout << "Test Copy constructor - on second object\n";
	FragTrap c(b);
	c.printStats();
	std::cout << "\n";

	std::cout << "Test Copy assignment operator - on second object\n";
	FragTrap d;
	d = b;
	b.printStats();
	std::cout << "\n";

	std::cout << "Test Copy constructor of ClapTrap on first object\n";
	ClapTrap x(a);
	x.printStats();
	std::cout << "\n";
}

void	testMethods(void)
{
	FragTrap a("Stu");
	FragTrap b("Lou");

	a.attack(b.getName());
	a.printStats();
	a.takeDamage(4);
	a.printStats();
	a.beRepaired(4);
	a.printStats();
}

void	testIsDead(int health)
{
	FragTrap a("MrDead");

	a.takeDamage(health);
	a.printStats();
	a.attack("Somebody");
}

void	testNoEnergy(int energyPoints)
{
	FragTrap a("MrEnergy");

	for (int i = 0; i < energyPoints; ++i) {
		a.beRepaired(10);
		a.printStats();
	}
	a.beRepaired(10);
}

void	testSpecialMethods(void)
{
	FragTrap a("Special");

	a.highFivesGuys();
}

int	main(void)
{
	DiamondTrap a;
	a.printStats();
	// testConstructDestruct();
	// std::cout << "---------------\n";
	// testMethods();
	// std::cout << "---------------\n";
	// testIsDead(100);
	// std::cout << "---------------\n";
	// testNoEnergy(100);
	// std::cout << "---------------\n";
	// testSpecialMethods();
}