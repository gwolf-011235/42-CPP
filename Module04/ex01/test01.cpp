/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:41:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 11:21:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	test01(void)
{
	testBrain();
	std::cout << "--- FINISHED ---\n\n";
	testCatWithBrain();
	std::cout << "--- FINISHED ---\n\n";
	testBaseClassPointer();
	std::cout << "--- FINISHED ---\n\n";
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

void	testCatWithBrain(void)
{
	std::cout << "--- TEST BrainCat ---\n\n";

	std::cout << "TEST Default constructor\n";
	Cat c1;
	c1.printThoughts();
	std::cout << std::endl;

	std::cout << "TEST Copy constructor\n";
	Cat c2(c1);
	c2.printThoughts();
	std::cout << std::endl;
}

void	testBaseClassPointer(void)
{
	std::cout << "--- TEST BaseClassPointer ---\n\n";

	std::cout << "TEST Fill array of base class pointer with Cats and Dogs:\n";
	Animal *array[10];
	for (int i = 0; i != 10; i += 2) {
		std::cout << "Array on index: " << i << "\n";
		array[i] = new Cat();
		std::cout << "Array on index: " << (i + 1) << "\n";
		array[i + 1] = new Dog();
	}
	std::cout << std::endl;

	std::cout << "TEST Use base class pointers:\n";
	std::cout << "Use pointer on index 0:\n";
	array[0]->introduce();
	array[0]->printThoughts();
	std::cout << std::endl;
	std::cout << "Use pointer on index 1:\n";
	array[1]->introduce();
	array[1]->printThoughts();
	std::cout << std::endl;

	std::cout << "TEST Delete array with for loop:\n";
	for (int i = 0; i != 10; ++i) {
		delete array[i];
	}
	std::cout << std::endl;
}