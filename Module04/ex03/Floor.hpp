/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:00:20 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 12:30:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

#define CAPACITY 10

class Floor
{
public:
	Floor(void);
	Floor(const std::string& name);
	Floor(const Floor& ref);
	~Floor(void);
	Floor& operator= (const Floor& ref);
	const std::string& getName() const;
	void	dropOnFloor(AMateria* m);
private:
	const std::string m_name;
	AMateria* m_storage[CAPACITY];
};
