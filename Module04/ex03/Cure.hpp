/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:31:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 23:58:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	// Ctor and Dtor
	Cure(void);
	Cure(const Cure& ref);
	~Cure(void);
	// Operators
	Cure& operator= (const Cure& ref);
	// Utility
	AMateria*	clone() const;
	void 		use(ICharacter& target);
};
