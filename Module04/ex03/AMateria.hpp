/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:06:53 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/16 23:12:10 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Floor.hpp"

class ICharacter;

class AMateria
{
private:
	enum e_place {CHAR, MATSRC, FLOOR};
	union u_ptr_place {ICharacter *c; IMateriaSource *ms; Floor *f;};
protected:
	const std::string m_type;
	AMateria::e_place m_place;
	AMateria::u_ptr_place m_ptr;
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	void assignPlace(ICharacter *c);
	void assignPlace(IMateriaSource * ms);
	void assignPlace(Floor *f);
};