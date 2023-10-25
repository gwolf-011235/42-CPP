/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:07:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/25 11:17:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// Driver function
void	runTests(void);
// Subject
void	testFromSubject(void);
// Class Character
void	testCharacterCtor(void);
void	testCharacterMethods(void);
// Class MateriaSource
void	testMateriaSourceCtor(void);
void	testMateriaSourceMethods(void);
// Exceed limits
void	testOverfill(void);