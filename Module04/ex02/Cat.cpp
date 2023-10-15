/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:36:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 19:56:30 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : A_Animal("Cat 🐱"), m_brain(new Brain()), m_cur_index(0)
{
	std::cout << "Default constructor called: Cat 🐱\n";
	haveThought("I am cat.");
	haveThought("I am great.");
	haveThought("Praise me!");
	std::cout << "Address hold by m_brain:\t" << m_brain << "\n";
}

Cat::Cat(const Cat& ref) : A_Animal("Cat 🐱")
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
		m_cur_index = ref.m_cur_index;
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

void	Cat::haveThought(const std::string& idea)
{
	m_brain->setIdea(idea, m_cur_index);
	if (++m_cur_index == 100)
		m_cur_index = 0;
}