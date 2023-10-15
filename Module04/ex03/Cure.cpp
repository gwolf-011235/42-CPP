/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:31:29 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 22:04:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Default constructor called: Cure \n";
}

Cure::Cure(const Cure& ref) : AMateria(ref.getType())
{
	std::cout << "Copy constructor called: Cure \n";
}

Cure& Cure::operator=(const Cure& ref)
{
	std::cout << "Copy assignment operator called: Cure \n";
}

Cure::~Cure(void)
{
	std::cout << "Destructor called: Cure \n";
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
