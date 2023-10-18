/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:06:53 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 12:01:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Floor.hpp"
#include "Entities.hpp"

class ICharacter;

class AMateria
{
protected:
	const std::string m_type;
	e_place m_place;
	std::string m_place_name;
	int m_idx;
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	void setPlace(e_place place_type, const std::string& place_name, int idx);
	bool hasPlace() const;
	void printPlace() const;
};