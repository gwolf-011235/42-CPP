/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:30:48 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/20 10:48:26 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::clog << "Default constructor called: Ice 🧊\n";
}

Ice::Ice(const Ice& ref) : AMateria(ref.getType())
{
	std::clog << "Copy constructor called: Ice 🧊\n";
}

Ice& Ice::operator=(const Ice& ref)
{
	std::clog << "Copy assignment operator called: Ice 🧊\n";
	if (&ref != this) {
		// Cannot copy, type is const
	}
	return *this;
}

Ice::~Ice(void)
{
	std::clog << "Destructor called: Ice 🧊\n";
}

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

