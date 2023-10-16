/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:00:20 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/16 22:06:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

#define CAPACITY 10

class Floor
{
public:
	Floor(void);
	Floor(const Floor& ref);
	~Floor(void);
	Floor& operator= (const Floor& ref);
	void	dropOnFloor(AMateria* m);
private:
	AMateria* m_storage[CAPACITY];
};
