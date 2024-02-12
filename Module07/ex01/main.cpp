/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:19:51 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 15:45:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>

template< typename T >
void	print(const T &x)
{
	std::cout << x << std::endl;
}

void	incrementInt(int &x)
{
	x++;
}

void	incrementFloat(float &x)
{
	x += 0.5;
}

void	incrementDbl(double &x)
{
	x += 0.3;
}

void	incrementString(std::string &x)
{
	x += "!";
}

int		main()
{
	int			intArray[] = {1, 2, 3, 4, 5};
	float		floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double		doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string	stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray:\n";
	iter(intArray, 5, print);
	std::cout << "Incrementing intArray by 1\n";
	iter(intArray, 5, incrementInt);
	std::cout << "new intArray:\n";
	iter(intArray, 5, print);
	std::cout << "\n";

	std::cout << "floatArray:\n";
	iter(floatArray, 5, print);
	std::cout << "Incrementing floatArray by 0.5\n";
	iter(floatArray, 5, incrementFloat);
	std::cout << "new floatArray:\n";
	iter(floatArray, 5, print);
	std::cout << "\n";

	std::cout << "doubleArray:\n";
	iter(doubleArray, 5, print);
	std::cout << "Incrementing doubleArray by 0.3\n";
	iter(doubleArray, 5, incrementDbl);
	std::cout << "new doubleArray:\n";
	iter(doubleArray, 5, print);
	std::cout << "\n";

	std::cout << "stringArray:\n";
	iter(stringArray, 5, print);
	std::cout << "Incrementing stringArray by !\n";
	iter(stringArray, 5, incrementString);
	std::cout << "new stringArray:\n";
	iter(stringArray, 5, print);
	std::cout << "\n";

	return 0;
}
