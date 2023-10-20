/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:33:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/20 10:49:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : m_name("Mako reactor")
{
	std::clog << "Default constructor called: MateriaSource 🔁\n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		m_memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const std::string& name) : m_name(name)
{
	std::clog << "Param constructor called: MateriaSource 🔁\n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		m_memory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ref) : m_name(ref.m_name)
{
	std::clog << "Copy constructor called: MateriaSource 🔁\n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		m_memory[i] = NULL;
		if (ref.m_memory[i] != NULL) {
			m_memory[i] = ref.m_memory[i]->clone();
			m_memory[i]->setPlace(MATERIASOURCE, m_name, i);
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ref)
{
	std::clog << "Copy assignment operator called: MateriaSource 🔁\n";
	if (this == &ref)
		return *this;
	AMateria* temp_memory[MEM_SPACE];
	for (int i = 0; i != MEM_SPACE; ++i) {
		temp_memory[i] = NULL;
		if (ref.m_memory[i] != NULL) {
			temp_memory[i] = ref.m_memory[i]->clone();
			temp_memory[i]->setPlace(MATERIASOURCE, m_name, i);
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
	std::clog << "Destructor called: MateriaSource 🔁\n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		delete m_memory[i];
	}
}

const std::string& MateriaSource::getName() const
{
	return m_name;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
		return;
	if (m->hasPlace()) {
		m->printPlace();
		return;
	}
	for (int i = 0; i != MEM_SPACE; ++i) {
		if (m_memory[i] == NULL) {
			m_memory[i] = m;
			m->setPlace(MATERIASOURCE, m_name, i);
			std::cout << getName() << " learned " << m->getType() << " in slot: " << i << "\n";
			return;
		}
	}
	std::cout << getName() << " has no space left in memory, the Materia vanishes\n";
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	std::cout << "Trying to create new materia of type " << type << "\n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		if (m_memory[i] && m_memory[i]->getType() == type) {
			std::cout << "Found match in slot " << i << "\n";
			return m_memory[i]->clone();

		}
	}
	std::cout << "No match found\n";
	return 0;
}

void MateriaSource::printInfo() const
{
	std::cout << "Name: " << getName() << "\n";
	for (int i = 0; i != MEM_SPACE; ++i) {
		std::cout << i << ": ";
		if (m_memory[i])
			std::cout << m_memory[i]->getType();
		else
			std::cout << "EMPTY";
		std::cout << "\n";
	}
}