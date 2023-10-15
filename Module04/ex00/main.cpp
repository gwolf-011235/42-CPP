/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:38:23 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 08:48:02 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	testAnimal(void);
void	testDog(void);
void	testCat(void);
void	testWrongAnimal(void);
void	testWrongCat(void);

int main(void)
{
	testAnimal();
	std::cout << "--- FINISHED ---\n\n";
	testDog();
	std::cout << "--- FINISHED ---\n\n";
	testCat();
	std::cout << "--- FINISHED ---\n\n";
	testWrongAnimal();
	std::cout << "--- FINISHED ---\n\n";
	testWrongCat();
	std::cout << "--- FINISHED ---\n\n";
	return 0;
}


void	testAnimal(void)
{
	std::cout << "--- TEST Animal ---\n\n";

	std::cout << "TEST Default constructor\n";
	Animal a1;
	a1.introduce();

	std::cout << "TEST Copy constructor\n";
	Animal a2(a1);
	a2.introduce();

	std::cout << "TEST Copy assignment operator\n";
	Animal a3;
	a3 = a1;
	a3.introduce();
}

void	testDog(void)
{
	std::cout << "--- TEST Dog ---\n\n";

	std::cout << "TEST Default constructor\n";
	Dog d1;
	d1.introduce();

	std::cout << "TEST Copy constructor\n";
	Dog d2(d1);
	d2.introduce();

	std::cout << "TEST Copy assignment operator\n";
	Dog d3;
	d3 = d1;
	d3.introduce();
}

void	testCat(void)
{
	std::cout << "--- TEST Cat ---\n\n";

	std::cout << "TEST Default constructor\n";
	Cat c1;
	c1.introduce();

	std::cout << "TEST Copy constructor\n";
	Cat c2(c1);
	c2.introduce();

	std::cout << "TEST Copy assignment operator\n";
	Cat c3;
	c3 = c1;
	c3.introduce();
}

void	testWrongAnimal(void)
{
	std::cout << "--- TEST WrongAnimal ---\n\n";

	std::cout << "TEST Default constructor\n";
	WrongAnimal w1;
	w1.introduce();

	std::cout << "TEST Copy constructor\n";
	WrongAnimal w2(w1);
	w2.introduce();

	std::cout << "TEST Copy assignment operator\n";
	WrongAnimal w3;
	w3 = w1;
	w3.introduce();
}

void	testWrongCat(void)
{
	std::cout << "--- TEST WrongCat ---\n\n";

	std::cout << "TEST Default constructor\n";
	WrongCat wc1;
	wc1.introduce();

	std::cout << "TEST Copy constructor\n";
	WrongCat wc2(wc1);
	wc2.introduce();

	std::cout << "TEST Copy assignment operator\n";
	WrongCat wc3;
	wc3 = wc1;
	wc3.introduce();
}