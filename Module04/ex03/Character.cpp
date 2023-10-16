/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:35 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/16 22:23:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Floor Character::s_floor;

Character::Character(void) : m_name("New Hero")
{
	std::cout << "Default constructor called: Character \n";
	for (int i = 0; i != 4; ++i) {
		m_inventory[i] = NULL;
	}
}

Character::Character(const std::string& name) : m_name(name)
{
	std::cout << "Param constructor called: Character \n";
	for (int i = 0; i != 4; ++i) {
		m_inventory[i] = NULL;
	}
}

Character::Character(const Character& ref) : m_name(ref.getName())
{
	std::cout << "Copy constructor called: Character \n";
	for (int i = 0; i != 4; ++i) {
		m_inventory[i] = ref.m_inventory[i];
	}
}

Character& Character::operator=(const Character& ref)
{
	std::cout << "Copy assignment operator called: Character \n";
	for (int i = 0; i != 4; ++i) {
		m_inventory[i] = ref.m_inventory[i];
	}
	return *this;
}

Character::~Character(void)
{
	std::cout << "Destructor called: Character \n";
}

std::string const & Character::getName() const
{
	return m_name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while (m_inventory[i] != NULL)
		i++;
	if (i > 3) {
		std::cout << "Cannot equip: Inventory full\n";
		return;
	}
	m_inventory[i] = m;
	std::cout << "Equipped " << m->getType() << " in slot: " << i << "\n";
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
	std::cout << "Unequipped " << m_inventory[idx]->getType() << " in slot: " << idx << "\n";
	s_floor.dropOnFloor(m_inventory[idx]);
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

