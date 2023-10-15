/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:03:43 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 19:55:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

A_Animal::A_Animal(void) : m_type("Animal 🐾")
{
	std::cout << "Default constructor called: Animal 🐾\n";
}

A_Animal::A_Animal(const std::string& type) : m_type(type)
{
	std::cout << "Param constructor called: Animal 🐾\n";
}

A_Animal::A_Animal(const A_Animal& ref)
{
	std::cout << "Copy constructor called: Animal 🐾\n";
	*this = ref;
}

A_Animal& A_Animal::operator=(const A_Animal& ref)
{
	std::cout << "Copy assignment operator called: Animal 🐾\n";
	if (&ref != this) {
		m_type = ref.m_type;
	}
	return *this;
}

A_Animal::~A_Animal(void)
{
	std::cout << "Destructor called: Animal 🐾\n";
}

const std::string&	A_Animal::getType() const
{
	return m_type;
}

void	A_Animal::introduce() const
{
	std::cout << "I am a: " << getType() << "\n";
	std::cout << "This is my sound: ";
	makeSound();
}