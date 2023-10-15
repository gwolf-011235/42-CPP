/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:36:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 07:57:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat 🙀")
{
	std::cout << "Default constructor called: WrongCat 🙀\n";
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal("WrongCat 🙀")
{
	std::cout << "Copy constructor called: WrongCat 🙀\n";
	*this = ref;
}

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
	std::cout << "Copy assignment operator called: WrongCat 🙀\n";
	if (&ref != this) {
		m_type = ref.getType();
	}
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor called: WrongCat 🙀\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "*meow*\n";
}