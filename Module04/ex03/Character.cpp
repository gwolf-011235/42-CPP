/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:35 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 13:00:15 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : m_name("New Hero"), m_current_floor(NULL)
{
	std::cout << "Default constructor called: Character \n";
	for (int i = 0; i != INV_SPACE; ++i) {
		m_inventory[i] = NULL;
	}
}

Character::Character(const std::string& name, Floor* current_floor) : m_name(name), m_current_floor(current_floor)
{
	std::cout << "Param constructor called: Character \n";
	for (int i = 0; i != INV_SPACE; ++i) {
		m_inventory[i] = NULL;
	}
}

Character::Character(const Character& ref) : m_name(ref.m_name), m_current_floor(ref.m_current_floor)
{
	std::cout << "Copy constructor called: Character \n";
	for (int i = 0; i != INV_SPACE; ++i) {
		if (ref.m_inventory[i] != NULL) {
			m_inventory[i] = ref.m_inventory[i]->clone();
			m_inventory[i]->setPlace(CHARACTER, m_name, i);
		}
	}
}

Character& Character::operator=(const Character& ref)
{
	std::cout << "Copy assignment operator called: Character \n";
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
	std::cout << "Destructor called: Character \n";
	for (int i = 0; i != INV_SPACE; ++i) {
		delete m_inventory[i];
	}
}

std::string const & Character::getName() const
{
	return m_name;
}

Floor* Character::getCurrentFloor() const
{
	return m_current_floor;
}

void Character::equip(AMateria* m)
{
	if (m->hasPlace()) {
		m->printPlace();
		return;
	}
	for (int i = 0; i != INV_SPACE; ++i) {
		if (m_inventory[i] == NULL) {
			m_inventory[i] = m;
			m->setPlace(CHARACTER, m_name, i);
			std::cout << "Equipped " << m->getType() << " in slot: " << i << "\n";
			return;
		}
	}
	std::cout << "No space left in inventory, the Materia falls on the floor\n";
	if (m_current_floor == NULL) {
		std::cout << "But there is no floor! The Materia vanishes\n";
		delete m;
		return;
	}
	m_current_floor->dropOnFloor(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3) {
		std::cout << "Cannot unequip: Not a valid slot\n";
		return;
	}
	if (m_inventory[idx] == NULL) {
		std::cout << "Cannot unequip: Nothing there\n";
		return;
	}
	std::cout << "Unequipped " << m_inventory[idx]->getType() << " in slot: " << idx << " and dropped on floor\n";
	if (m_current_floor == NULL) {
		std::cout << "But there is no floor! The Materia vanishes\n";
		delete m_inventory[idx];
		return;
	}
	m_current_floor->dropOnFloor(m_inventory[idx]);
	m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3) {
		std::cout << "Cannot use: Not a valid slot\n";
		return;
	}
	if (m_inventory[idx] == NULL) {
		std::cout << "Cannot use: Nothing there\n";
		return;
	}
	m_inventory[idx]->use(target);
}

