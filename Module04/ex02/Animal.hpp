/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:01:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 19:55:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class A_Animal
{
public:
	A_Animal(void);
	A_Animal(const A_Animal& ref);
	virtual ~A_Animal(void);
	A_Animal& operator= (const A_Animal& ref);
	const std::string&	getType() const;
	virtual void	makeSound() const = 0;
	void	introduce() const;
	virtual void	printThoughts() const = 0;
protected:
	std::string	m_type;
	A_Animal(const std::string& type);
};