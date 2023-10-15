/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:14:09 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 10:32:00 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor called: Brain 🧠\n";
}

Brain::Brain(const Brain& ref)
{
	std::cout << "Copy constructor called: Brain 🧠\n";
	*this = ref;
}

Brain& Brain::operator=(const Brain& ref)
{
	std::cout << "Copy assignment operator called: Brain 🧠\n";
	if (&ref != this) {
		for (int i = 0; i != 100; ++i) {
			this->ideas[i] = ref.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Destructor called: Brain 🧠\n";
}

void	Brain::setIdea(const std::string& idea, int index, bool print)
{
	if (index < 0 || index > 99) {
		std::cout << "Set idea failed: Out of bounds\n";
		return ;
	}
	ideas[index] = idea;
	if (print) {
		std::cout << "Set idea on index " << index << ": " << ideas[index] << "\n";
	}
}

void	Brain::printIdea(int index) const
{
	if (index < 0 || index > 99) {
		std::cout << "Print idea failed: Out of bounds\n";
		return ;
	}
	std::cout << "Idea with index " << index << " is: " << ideas[index] << "\n";
}

void	Brain::printEverything() const
{
	for (int i = 0; i != 100; ++i) {
		printIdea(i);
	}
}

