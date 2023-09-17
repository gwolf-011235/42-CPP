/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:38:47 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 13:55:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

int main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << std::left;

	std::cout << std::setw(45) << "The memory address of the string variable:" << &string << std::endl;
	std::cout << std::setw(45) << "The memory address held by stringPTR:" << stringPTR << std::endl;
	std::cout << std::setw(45) << "The memory address held by stringREF:" << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << std::setw(45) << "The value of the string variable:" << string << std::endl;
	std::cout << std::setw(45) << "The value pointed to by stringPTR:" << *stringPTR << std::endl;
	std::cout << std::setw(45) << "The value pointed to by stringREF:" << stringREF << std::endl;

	return 0;
}