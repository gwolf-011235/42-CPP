/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:06:57 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/07 22:37:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

enum e_choice
{
	INVALID,
	ADD,
	SEARCH,
	EXIT
};

e_choice resolveChoice(std::string input)
{
	if (input == "ADD") return e_choice::ADD;
	else if (input == "SEARCH") return e_choice::SEARCH;
	else if (input == "EXIT") return e_choice::EXIT;
	else return e_choice::INVALID;
}

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: exit the program" << std::endl;
	std::cout << "Please enter a keyword: ";
	std::cin >> input;

	switch (resolveChoice(input))
	{
		case e_choice::ADD:
			std::cout << "ADD was entered" << std::endl;
			break;

		default:
			std::cout << "Not recognised" << std::endl;
			break;
	}

}