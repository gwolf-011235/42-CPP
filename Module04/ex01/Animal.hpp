/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:01:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 10:58:40 by gwolf            ###   ########.fr       */
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
	virtual ~Animal(void);
	Animal& operator= (const Animal& ref);
	const std::string&	getType() const;
	virtual void	makeSound() const;
	void	introduce() const;
	virtual void	printThoughts() const;
protected:
	std::string	m_type;
	Animal(const std::string& type);
};