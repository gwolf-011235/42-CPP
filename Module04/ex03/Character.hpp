/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 23:57:55 by gwolf            ###   ########.fr       */
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
	// Ctor and Dtor
	Character(void);
	Character(const std::string& name);
	Character(const Character& ref);
	~Character(void);
	// Operators
	Character& operator= (const Character& ref);
	// Getters
	std::string const & getName() const;
	// Utility
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
	// Print
	void	printInfo() const;
private:
	const std::string m_name;
	AMateria* m_inventory[INV_SPACE];
	static Floor s_floor;
};
