/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test01.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:41:08 by gwolf             #+#    #+#             */
/*   Updated: 2024/05/01 13:15:41 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	test01(void)
{
	testBrain();
	std::cout << "--- FINISHED ---\n\n";
	testDogWithBrain();
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

void	testDogWithBrain(void)
{
	std::cout << "--- TEST Dog with Brain ---\n\n";

	std::cout << "TEST Default constructor\n";
	Dog d1;
	d1.printThoughts();
	std::cout << std::endl;

	std::cout << "TEST Copy constructor\n";
	Dog d2(d1);
	d2.printThoughts();
	std::cout << std::endl;

	std::cout << "TEST Copy assignment operator\n";
	Dog d3;
	d3 = d1;
	d3.printThoughts();
	std::cout << std::endl;
}

void	testCatWithBrain(void)
{
	std::cout << "--- TEST Cat with Brain ---\n\n";

	std::cout << "TEST Default constructor\n";
	Cat c1;
	c1.haveThought("I don't want to be tested!");
	c1.haveThought("Release me or I shall rain pain upon you!");
	c1.haveThought("What is this red dot?");
	c1.haveThought("I shall exterminate you, puny little dot!");
	c1.haveThought("Heureka! The dot is gone, another proof of my superiority!");
	c1.haveThought("I shall sleep now.");
	c1.haveThought("*purr*");
	c1.printThoughts();
	std::cout << std::endl;

	std::cout << "TEST Copy constructor\n";
	Cat c2(c1);
	c2.printThoughts();
	std::cout << std::endl;

	std::cout << "TEST Copy assignment operator\n";
	Cat c3;
	c3 = c1;
	c3.printThoughts();
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

