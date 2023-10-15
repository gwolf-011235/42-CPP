/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:01:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 08:11:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
	Animal(void);
	Animal(const Animal& ref);
	~Animal(void);
	Animal& operator= (const Animal& ref);
	const std::string&	getType() const;
	virtual void	makeSound() const;
protected:
	std::string	m_type;
	Animal(const std::string& type);
};