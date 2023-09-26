/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:17:34 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/26 14:03:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {
private:
	std::string	name;
	Weapon&		weapon;
public:
	void	attack(void) const;
	HumanA(const std::string& new_name, Weapon& new_weapon);
	~HumanA(void);
};

#endif