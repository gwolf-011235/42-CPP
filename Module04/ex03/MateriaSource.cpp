/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:33:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 12:57:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : m_name("Mako reactor"), m_current_floor(NULL)
{
	std::cout << "Default constructor called: MateriaSource \n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		m_memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const std::string& name, Floor* current_floor) : m_name(name), m_current_floor(current_floor)
{
	std::cout << "Param constructor called: MateriaSource \n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		m_memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
	std::cout << "Copy constructor called: MateriaSource \n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		if (ref.m_memory[i] != NULL) {
			m_memory[i] = ref.m_memory[i]->clone();
			m_memory[i]->setPlace(MATERIASOURCE, m_name, i);
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ref)
{
	std::cout << "Copy assignment operator called: MateriaSource \n";
	if (this == &ref)
		return *this;
	AMateria* temp_memory[MEM_SPACE];
	for (int i = 0; i != MEM_SPACE; ++i) {
		temp_memory[i] = NULL;
		if (ref.m_memory[i] != NULL) {
			temp_memory[i] = ref.m_memory[i]->clone();
			temp_memory[i]->setPlace(CHARACTER, m_name, i);
		}
	}
	for (int i = 0; i != MEM_SPACE; ++i) {
		delete m_memory[i];
		m_memory[i] = temp_memory[i];
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "Destructor called: MateriaSource \n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		delete m_memory[i];
	}
}

const std::string& MateriaSource::getName() const
{
	return m_name;
}

Floor* MateriaSource::getCurrentFloor() const
{
	return m_current_floor;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m->hasPlace()) {
		m->printPlace();
		return;
	}
	for (int i = 0; i != MEM_SPACE; ++i) {
		if (m_memory[i] == NULL) {
			m_memory[i] = m;
			m->setPlace(MATERIASOURCE, m_name, i);
			std::cout << "Learned " << m->getType() << " in slot: " << i << "\n";
			return;
		}
	}
	std::cout << "No space left in memory, the Materia falls on the floor\n";
	if (m_current_floor == NULL) {
		std::cout << "But there is no floor! The Materia vanishes\n";
		delete m;
		return;
	}
	m_current_floor->dropOnFloor(m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	std::cout << "Trying to create new materia\n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		if (m_memory[i] && m_memory[i]->getType() == type) {
			std::cout << "Found match in slot " << i << "\n";
			return m_memory[i]->clone();

		}
	}
	std::cout << "No match found\n";
	return 0;

}