/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:13:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 19:55:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
public:
	Dog(void);
	Dog(const Dog& ref);
	~Dog(void);
	Dog& operator= (const Dog& ref);
	void	makeSound() const;
	void	printThoughts() const;
private:
	Brain* m_brain;
};