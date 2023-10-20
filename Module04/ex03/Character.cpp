/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:35 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 19:40:30by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Floor Character::s_floor;

Character::Character(void) : m_name("New Hero")
{
	std::clog << "Default constructor called: Character 👤\n";
	for (int i = 0; i != INV_SPACE; ++i) {
		m_inventory[i] = NULL;
	}
}

Character::Character(const std::string& name) : m_name(name)
{
	std::clog << "Param constructor called: Character 👤\n";
	for (int i = 0; i != INV_SPACE; ++i) {
		m_inventory[i] = NULL;
	}
}

Character::Character(const Character& ref) : m_name(ref.m_name)
{
	std::clog << "Copy constructor called: Character 👤\n";
	for (int i = 0; i != INV_SPACE; ++i) {
		m_inventory[i] = NULL;
		if (ref.m_inventory[i] != NULL) {
			m_inventory[i] = ref.m_inventory[i]->clone();
			m_inventory[i]->setPlace(CHARACTER, m_name, i);
		}
	}
}

Character& Character::operator=(const Character& ref)
{
	std::clog << "Copy assignment operator called: Character 👤\n";
	if (this == &ref)
		return *this;
	AMateria* temp_inventory[INV_SPACE];
	for (int i = 0; i != INV_SPACE; ++i) {
		temp_inventory[i] = NULL;
		if (ref.m_inventory[i] != NULL) {
			temp_inventory[i] = ref.m_inventory[i]->clone();
			temp_inventory[i]->setPlace(CHARACTER, m_name, i);
		}
	}
	for (int i = 0; i != INV_SPACE; ++i) {
		delete m_inventory[i];
		m_inventory[i] = temp_inventory[i];
	}
	return *this;
}

Character::~Character(void)
{
	std::clog << "Destructor called: Character 👤\n";
	for (int i = 0; i != INV_SPACE; ++i) {
		delete m_inventory[i];
	}
}

std::string const & Character::getName() const
{
	return m_name;
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return;
	if (m->hasPlace()) {
		std::cout << getName() << " cannot equip the materia, it is already somewhere\n";
		m->printPlace();
		return;
	}
	for (int i = 0; i != INV_SPACE; ++i) {
		if (m_inventory[i] == NULL) {
			m_inventory[i] = m;
			m->setPlace(CHARACTER, m_name, i);
			std::cout << getName() << " equipped <" << m->getType() << "> in slot <" << i << ">\n";
			return;
		}
	}
	std::cout << getName() << " has no space left in inventory, the Materia falls on the floor\n";
	s_floor.dropOnFloor(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3) {
		std::cout << getName() << " cannot unequip: <" << idx << "> is not a valid slot\n";
		return;
	}
	if (m_inventory[idx] == NULL) {
		std::cout << getName() << " cannot unequip: The slot <" << idx << "> is empty\n";
		return;
	}
	m_inventory[idx]->setPlace(NONE, "", -1);
	std::cout << getName() << " unequipped <" << m_inventory[idx]->getType() << "> of slot <" << idx << "> and dropped it on the floor\n";
	s_floor.dropOnFloor(m_inventory[idx]);
	m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3) {
		std::cout << getName() << " cannot use: <" << idx << "> is not a valid slot\n";
		return;
	}
	if (m_inventory[idx] == NULL) {
		std::cout << getName() << " cannot use: The slot <" << idx << "> is empty\n";
		return;
	}
	m_inventory[idx]->use(target);
}

void Character::printInfo() const
{
	std::cout << "Name: " << getName() << "\n";
	for (int i = 0; i != INV_SPACE; ++i) {
		std::cout << i << ": ";
		if (m_inventory[i])
			std::cout << m_inventory[i]->getType();
		else
			std::cout << "EMPTY";
		std::cout << "\n";
	}
}
