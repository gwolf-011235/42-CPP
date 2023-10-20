/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:00:38 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/20 10:47:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor(void): m_name("Floor")
{
	std::clog << "Default constructor called: Floor 🔲\n";
	for (int i = 0; i != CAPACITY; ++i) {
		m_storage[i] = NULL;
	}
}

Floor::Floor(const std::string& name): m_name(name)
{
	std::clog << "Param constructor called: Floor 🔲\n";
	for (int i = 0; i != CAPACITY; ++i) {
		m_storage[i] = NULL;
	}
}

Floor::Floor(const Floor& ref)
{
	std::clog << "Copy constructor called: Floor 🔲\n";
	for (int i = 0; i != CAPACITY; ++i) {
		if (ref.m_storage[i] != NULL) {
			m_storage[i] = ref.m_storage[i]->clone();
			m_storage[i]->setPlace(FLOOR, m_name, i);
		}
	}
}

Floor& Floor::operator=(const Floor& ref)
{
	std::clog << "Copy assignment operator called: Floor 🔲\n";
	if (this == &ref)
		return *this;
	AMateria* temp_storage[CAPACITY];
	for (int i = 0; i != CAPACITY; ++i) {
		temp_storage[i] = NULL;
		if (ref.m_storage[i] != NULL) {
			m_storage[i] = ref.m_storage[i]->clone();
			m_storage[i]->setPlace(FLOOR, m_name, i);
		}
	}
	for (int i = 0; i != CAPACITY; ++i) {
		delete m_storage[i];
		m_storage[i] = temp_storage[i];
	}
	return *this;
}

Floor::~Floor(void)
{
	std::clog << "Destructor called: Floor 🔲\n";
	for (int i = 0; i != CAPACITY; ++i) {
			delete m_storage[i];
	}
}

const std::string& Floor::getName() const
{
	return m_name;
}

void	Floor::dropOnFloor(AMateria* m)
{
	if (m->hasPlace()) {
		m->printPlace();
		return;
	}
	for (int i = 0; i != CAPACITY; ++i) {
		if (m_storage[i] == NULL) {
			m_storage[i] = m;
			m->setPlace(FLOOR, m_name, i);
			std::cout << "The Materia " << m->getType() << " lies on the floor on tile: " << i << "\n";
			return;
		}
	}
	std::cout << "No space left on the floor, the Materia shatters\n";
	delete m;
}