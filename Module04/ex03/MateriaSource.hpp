/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:58 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/16 20:23:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class MateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& ref);
	~MateriaSource(void);
	MateriaSource& operator= (const MateriaSource& ref);
private:
	/* private stuff */
};
