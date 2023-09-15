/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:06:57 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/15 12:25:47 by gwolf            ###   ########.fr       */
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

void	printOptions(void)
{
	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: exit the program" << std::endl;
	std::cout << std::endl << "Please enter a keyword: ";
}

#define CLEAR_SCREEN "\033[2J\033[1;1H";

int	main(void)
{
	PhoneBook 	phonebook;
	std::string input;
	bool		loop;

	loop = true;
	std::cout << CLEAR_SCREEN
	std::cout << "My awesome phonebook program!" << std::endl << std::endl;
	do
	{
		printOptions();

		if (!getline(std::cin, input))
		{
			std::cout << "EOF received - Aborting." << std::endl;
			break;
		}

		switch (resolveChoice(input))
		{
			case ADD:
				phonebook.AddContact();
				std::cout << CLEAR_SCREEN
				std::cout << "Contact was added!\n" << std::endl;
				break;

			case SEARCH:
				phonebook.SearchContact();
				break;

			case EXIT:
				std::cout << "EXIT was entered - goodbye" << std::endl;
				loop = false;
				break;

			default:
				std::cout << "\"" << input << "\": Not recognised" << std::endl << std::endl;
				break;
		}
	} while (loop);



}