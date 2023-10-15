/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:35 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 21:32:41 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Default constructor called: Character \n";
}

Character::Character(const Character& ref)
{
	std::cout << "Copy constructor called: Character \n";
}

Character& Character::operator=(const Character& ref)
{
	std::cout << "Copy assignment operator called: Character \n";
}

Character::~Character(void)
{
	std::cout << "Destructor called: Character \n";
}
