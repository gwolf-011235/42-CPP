/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:41:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 10:22:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	testBrainCat(void)
{
	std::cout << "--- TEST BrainCat ---\n\n";

	std::cout << "TEST Default constructor\n";
	Cat c1;
	c1.printCatThoughts();
	std::cout << std::endl;

	std::cout << "TEST Copy constructor\n";
	Cat c2(c1);
	c2.printCatThoughts();
	std::cout << std::endl;

}

void	testBrain(void)
{
	std::cout << "--- TEST Brain ---\n\n";

	std::cout << "TEST Default constructor\n";
	Brain b1;
	b1.setIdea("I think therefore I am", 0, true);
	b1.printIdea(0);
	b1.setIdea("How Can Mirrors Be Real If Our Eyes Aren't Real", 46, true);
	b1.printIdea(46);
	b1.setIdea("Programming in C++ is like sculpting with logic and creativity.", 73, true);
	b1.printIdea(73);
	b1.setIdea("Oh no", 100, true);
	b1.printIdea(100);
	std::cout << std::endl;

	std::cout << "TEST Copy constructor\n";
	Brain b2(b1);
	b2.printEverything();
	std::cout << std::endl;

	std::cout << "TEST Copy assignment operator\n";
	Brain b3;
	b3 = b1;
	b2.printEverything();
	std::cout << std::endl;

}