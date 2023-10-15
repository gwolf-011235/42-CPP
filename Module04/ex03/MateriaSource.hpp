/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:58 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 21:33:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
