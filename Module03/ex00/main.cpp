/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:22:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/08 11:30:22 by gwolf            ###   ########.fr       */
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
	a.printStats();
	a.takeDamage(4);
	a.printStats();
	a.beRepaired(4);
	a.printStats();
	a.takeDamage(50);
	a.printStats();
	a.attack(b.getName());

	for (int i = 0; i < 10; ++i) {
		b.beRepaired(10);
		b.printStats();
	}
	b.beRepaired(10);
}