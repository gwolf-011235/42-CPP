/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:36:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 07:57:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat 🐱")
{
	std::cout << "Default constructor called: Cat 🐱\n";
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
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Destructor called: Cat 🐱\n";
}

void	Cat::makeSound() const
{
	std::cout << "*meow*\n";
}