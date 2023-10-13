/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
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

class Animal
{
public:
	Animal(void);
	Animal(const std::string& type);
	Animal(const Animal& ref);
	~Animal(void);
	Animal& operator= (const Animal& ref);

	const std::string&	getType() const;

	virtual void	makeSound() const;
protected:
	std::string	m_type;
};