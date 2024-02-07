/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:27:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/07 16:38:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	std::cout << "Generating random class:\n";
	int	rand = std::rand() % 3;
	if (rand == 0)
		return (new A());
	else if (rand == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	std::cout << "Identifying class by pointer:\n";
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "It's class A\n";
	else if (b)
		std::cout << "It's class B\n";
	else if (c)
		std::cout << "It's class C\n";
	else
		std::cout << "Unknown\n";
}

void identify(Base& p)
{
	std::cout << "Identifying class by reference:\n";
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "It's class A\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "It is not A: " << e.what() << '\n';
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "It's class B\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "It is not B: " << e.what() << '\n';
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "It's class C\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "It is not C: " << e.what() << '\n';
	}

}

int	main(void)
{
	std::srand(std::time(0));
	for (int i = 1; i <= 5; ++i)
	{
		std::cout << "Iteration: " << i << std::endl;
		Base	*base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	return (0);
}
