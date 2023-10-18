/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 13:09:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"

#define INV_SPACE 4

class Character : public ICharacter
{
public:
	Character(void);
	Character(const std::string& name, Floor* current_floor = NULL);
	Character(const Character& ref);
	~Character(void);
	Character& operator= (const Character& ref);
	std::string const & getName() const;
	Floor* getCurrentFloor() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	const std::string m_name;
	AMateria* m_inventory[INV_SPACE];
	Floor* m_current_floor;
};
