/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:58 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 13:08:15 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define MEM_SPACE 4

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const std::string& name, Floor* current_floor);
	MateriaSource(const MateriaSource& ref);
	~MateriaSource(void);
	MateriaSource& operator= (const MateriaSource& ref);
	const std::string& getName() const;
	Floor* getCurrentFloor() const;
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);

private:
	const std::string m_name;
	AMateria *m_memory[MEM_SPACE];
	Floor* m_current_floor;
};
