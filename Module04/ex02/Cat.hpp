/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:43:59 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 19:55:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal
{
public:
	Cat(void);
	Cat(const Cat& ref);
	~Cat(void);
	Cat& operator= (const Cat& ref);
	void	makeSound() const;
	void	printThoughts() const;
	void	haveThought(const std::string& idea);
private:
	Brain*	m_brain;
	int		m_cur_index;
};