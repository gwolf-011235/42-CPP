/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:03:43 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 08:50:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : m_type("Animal 🐾")
{
	std::cout << "Default constructor called: Animal 🐾\n";
}

Animal::Animal(const std::string& type) : m_type(type)
{
	std::cout << "Param constructor called: Animal 🐾\n";
}

Animal::Animal(const Animal& ref)
{
	std::cout << "Copy constructor called: Animal 🐾\n";
	*this = ref;
}

Animal& Animal::operator=(const Animal& ref)
{
	std::cout << "Copy assignment operator called: Animal 🐾\n";
	if (&ref != this) {
		m_type = ref.m_type;
	}
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Destructor called: Animal 🐾\n";
}

const std::string&	Animal::getType() const
{
	return m_type;
}

void	Animal::makeSound() const
{
	std::cout << "*abstract noise*\n";
}

void	Animal::introduce() const
{
	std::cout << "I am a: " << getType() << "\n";
	std::cout << "This is my sound: ";
	makeSound();
	std::cout << std::endl;
}