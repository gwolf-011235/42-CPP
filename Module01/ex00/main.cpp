/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:44:06 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 12:52:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
	Zombie *ptr;

	randomChump("Gabriel");
	ptr = newZombie("Evaluator");
	ptr->announce();
	randomChump("Inbetween");
	delete ptr;
}