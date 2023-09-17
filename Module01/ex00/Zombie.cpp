/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:11:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 12:49:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name("unknown")
{
	std::cout << "Zombie " << name << ": Default constructor is called." << std::endl;
	announce();
}

Zombie::Zombie(std::string zombie_name) : name(zombie_name)
{
	std::cout << "Zombie " << name << ": Param constructor is called." << std::endl;
	announce();
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << ": Destructor is called." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
