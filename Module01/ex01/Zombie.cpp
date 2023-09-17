/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:11:00 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 13:24:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name("Nobody")
{
	std::cout << "Zombie " << name << ": Default constructor is called." << std::endl;
}

Zombie::Zombie(const std::string& zombie_name) : name(zombie_name)
{
	std::cout << "Zombie " << name << ": Param constructor is called." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << ": Destructor is called." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
