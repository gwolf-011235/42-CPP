/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:31:29 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/20 10:46:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::clog << "Default constructor called: Cure ✨\n";
}

Cure::Cure(const Cure& ref) : AMateria(ref.getType())
{
	std::clog << "Copy constructor called: Cure ✨\n";
}

Cure& Cure::operator=(const Cure& ref)
{
	std::clog << "Copy assignment operator called: Cure ✨\n";
	if (&ref != this) {
		// Cannot copy, type is const
	}
	return *this;
}

Cure::~Cure(void)
{
	std::clog << "Destructor called: Cure ✨\n";
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
