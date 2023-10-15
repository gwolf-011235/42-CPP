/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 22:15:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character(void);
	Character(const std::string& name);
	Character(const Character& ref);
	~Character(void);
	Character& operator= (const Character& ref);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	const std::string m_name;
	AMateria* m_inventory[4] = {nullptr};
};
