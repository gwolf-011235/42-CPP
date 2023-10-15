/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:03:43 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 07:56:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : m_type("WrongAnimal ❓")
{
	std::cout << "Default constructor called: WrongAnimal ❓\n";
}

WrongAnimal::WrongAnimal(const std::string& type) : m_type(type)
{
	std::cout << "Param constructor called: WrongAnimal ❓\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
	std::cout << "Copy constructor called: WrongAnimal ❓\n";
	*this = ref;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	std::cout << "Copy assignemnt operator called: WrongAnimal ❓\n";
	if (&ref != this) {
		m_type = ref.m_type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor called: WrongAnimal ❓\n";
}

const std::string&	WrongAnimal::getType() const
{
	return m_type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*abstract noise*\n";
}

void	WrongAnimal::introduce() const
{
	std::cout << "I am a: " << getType() << "\n";
	std::cout << "This is my sound: ";
	makeSound();
	std::cout << std::endl;
}