/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:17:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/26 14:03:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
private:
	std::string	name;
	Weapon*		weapon;
	HumanB(void);
public:
	void	attack(void) const;
	void	setWeapon(Weapon& new_weapon);
	HumanB(const std::string& new_name);
	~HumanB(void);
};

#endif