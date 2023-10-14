/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:14:24 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/14 21:55:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default constructor called: Dog \n";
}

Dog::Dog(const Dog& ref) : Animal("Dog")
{
	std::cout << "Copy constructor called: Dog \n";
	*this = ref;
}

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << "Copy assignment operator called: Dog \n";
	if (&ref != this) {
		m_type = ref.getType();
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Destructor called: Dog \n";
}

void	Dog::makeSound() const
{
	std::cout << "I am " << getType() << " and I bark: woof woof\n";
}
