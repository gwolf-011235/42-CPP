/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:30:27 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 23:59:26 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	// Ctor and Dtor
	Ice(void);
	Ice(const Ice& ref);
	~Ice(void);
	// Operators
	Ice& operator= (const Ice& ref);
	// Utility
	AMateria*	clone() const;
	void 		use(ICharacter& target);
};
