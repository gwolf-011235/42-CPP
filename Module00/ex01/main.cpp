/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:06:57 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/14 08:18:36 by gwolf            ###   ########.fr       */
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
	if (input == "ADD") return ADD;
	else if (input == "SEARCH") return SEARCH;
	else if (input == "EXIT") return EXIT;
	else return INVALID;
}

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: exit the program" << std::endl;
	std::cout << "Please enter a keyword: ";
	std::getline(std::cin, input);

	switch (resolveChoice(input))
	{
		case ADD:
			phonebook.AddContact();
			break;

		case SEARCH:
			std::cout << "SEARCH was entered" << std::endl;
			break;

		case EXIT:
			std::cout << "EXIT was entered" << std::endl;
			break;

		default:
			std::cout << "Not recognised" << std::endl;
			break;
	}

}