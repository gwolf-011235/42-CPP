/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:08:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 15:15:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
private:
	std::string type;
	Weapon(void);
public:
	Weapon(const std::string& new_type);
	~Weapon(void);
	const std::string&	getType(void);
	void				setType(const std::string& new_type);
};

#endif