/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:36:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 10:58:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat 🐱"), m_brain(new Brain())
{
	std::cout << "Default constructor called: Cat 🐱\n";
	for (int i = 0; i != 100; ++i) {
		m_brain->setIdea("That bird outside looks like a tasty treat.", i);
	}
	m_brain->setIdea("Special Thought: I kill and eat", 66);
	std::cout << "Address hold by m_brain:\t" << m_brain << "\n";
}

Cat::Cat(const Cat& ref) : Animal("Cat 🐱")
{
	std::cout << "Copy constructor called: Cat 🐱\n";
	*this = ref;
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << "Copy assignment operator called: Cat 🐱\n";
	if (&ref != this) {
		m_type = ref.getType();
		m_brain = new Brain();
		*m_brain = *(ref.m_brain);
		std::cout << "Address hold by orig:\t" << ref.m_brain << "\n";
		std::cout << "Address hold by copy:\t" << m_brain << "\n";
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Destructor called: Cat 🐱\n";
	delete m_brain;
}

void	Cat::makeSound() const
{
	std::cout << "*meow*\n";
}

void	Cat::printThoughts() const
{
	m_brain->printEverything();
}