/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:01:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/13 15:44:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& ref);
	~WrongAnimal(void);
	WrongAnimal& operator= (const WrongAnimal& ref);
	const std::string&	getType() const;
	void	makeSound() const;
	void	introduce() const;
protected:
	std::string	m_type;
	WrongAnimal(const std::string& type);
};