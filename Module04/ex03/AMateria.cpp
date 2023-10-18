/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:08:10 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 17:03:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : m_type(type), m_place(NONE), m_place_name("SPACE"), m_idx(-1)
{
	std::cout << "Param constructor called: AMateria ⚪\n";
}

AMateria::~AMateria()
{
	std::cout << "Destructor called: AMateria ⚪\n";
}

std::string const & AMateria::getType() const
{
	return m_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "*The materia " << getType() << " was used on " << target.getName() << "*\n";
}

void AMateria::setPlace(e_place place_type, const std::string& place_name, int idx)
{
	m_place = place_type;
	m_place_name = place_name;
	m_idx = idx;
}

bool AMateria::hasPlace() const
{
	if (m_place == NONE)
		return false;
	return true;
}

void AMateria::printPlace() const
{
	switch (m_place) {
		case CHARACTER:
			std::cout << "The materia " << getType() << " is in the inventory of " << m_place_name << " in slot " << m_idx << "\n";
			break;
		case MATERIASOURCE:
			std::cout << "The materia " << getType() << " is stored in the memory of " << m_place_name << " in slot " << m_idx << "\n";
			break;
		case FLOOR:
			std::cout << "The materia " << getType() << " lies on the floor on tile " << m_idx << "\n";
			break;
		default:
			std::cout << "The materia " << getType() << " is floating in space!\n";
	}
}