/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:33:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 21:33:22 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "Default constructor called: MateriaSource \n";
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
	std::cout << "Copy constructor called: MateriaSource \n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ref)
{
	std::cout << "Copy assignment operator called: MateriaSource \n";
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "Destructor called: MateriaSource \n";
}
