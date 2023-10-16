/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:08:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/16 23:13:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : m_type(type)
{
	std::cout << "Default constructor called: AMateria \n";
}

AMateria::~AMateria()
{
	std::cout << "Destructor called: AMateria \n";
}

std::string const & AMateria::getType() const
{
	return m_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "*The materia " << getType() << " was used on " << target.getName() << "*\n";
}

void AMateria::assignPlace(ICharacter *c)
{
	m_place = CHAR;
	m_ptr.c = c;
}

void AMateria::assignPlace(IMateriaSource * ms)
{
	m_place = MATSRC;
	m_ptr.ms = ms;
}

void AMateria::assignPlace(Floor *f)
{
	m_place = FLOOR;
	m_ptr.f = f;
}
