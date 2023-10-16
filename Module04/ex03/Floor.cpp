/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:00:38 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/16 22:15:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor(void)
{
	std::cout << "Default constructor called: Floor \n";
	for (int i = 0; i != CAPACITY; ++i) {
		m_storage[i] = NULL;
	}
}

Floor::Floor(const Floor& ref)
{
	std::cout << "Copy constructor called: Floor \n";
	*this = ref;
}

Floor& Floor::operator=(const Floor& ref)
{
	std::cout << "Copy assignment operator called: Floor \n";
	if (&ref != this) {
		for (int i = 0; i != CAPACITY; ++i) {
			if (ref.m_storage[i]) {
				m_storage[i] = ref.m_storage[i]->clone();
			}
		}
	}
	return *this;
}

Floor::~Floor(void)
{
	std::cout << "Destructor called: Floor \n";
	for (int i = 0; i != CAPACITY; ++i) {
			delete m_storage[i];
	}
}

void	Floor::dropOnFloor(AMateria* m)
{
	for (int i = 0; i != CAPACITY; ++i) {
		if (m_storage[i] == NULL) {
			m_storage[i] = m;
			//reflect placement
			break;
		}
	}
}