/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:14:24 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 10:58:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog 🐶"), m_brain(new Brain())
{
	std::cout << "Default constructor called: Dog 🐶\n";
	for (int i = 0; i != 100; ++i) {
		m_brain->setIdea("Food! Play! Fun!", i);
	}
	m_brain->setIdea("Special Thought: I love you!", 12);
	std::cout << "Address hold by m_brain:\t" << m_brain << "\n";
}

Dog::Dog(const Dog& ref) : Animal("Dog 🐶")
{
	std::cout << "Copy constructor called: Dog 🐶\n";
	*this = ref;
}

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << "Copy assignment operator called: Dog 🐶\n";
	if (&ref != this) {
		m_type = ref.getType();
		m_brain = new Brain();
		*m_brain = *(ref.m_brain);
		std::cout << "Address hold by orig:\t" << ref.m_brain << "\n";
		std::cout << "Address hold by copy:\t" << m_brain << "\n";
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Destructor called: Dog 🐶\n";
	delete m_brain;
}

void	Dog::makeSound() const
{
	std::cout << "*woof woof*\n";
}

void	Dog::printThoughts() const
{
	m_brain->printEverything();
}