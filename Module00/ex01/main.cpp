/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:06:57 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/15 18:24:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "PhoneBook.hpp"
#include "colors.hpp"

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
	std::cout << YELLOW "ADD" RESET ": save a new contact\n";
	std::cout << YELLOW "SEARCH" RESET ": display a specific contact\n";
	std::cout << YELLOW "EXIT" RESET ": exit the program\n";
	std::cout << "\n\nPlease enter a " YELLOW "keyword: " RESET;
}


int	main(void)
{
	PhoneBook 	phonebook;
	std::string input;
	bool		loop;
	bool		ret;

	loop = true;
	std::cout << CLEAR_SCREEN
	std::cout << BOLD << BLUE << "My awesome phonebook program!\n\n" << RESET;
	do
	{
		printOptions();

		if (!getline(std::cin, input))
		{
			std::cout << RED "EOF received - Aborting.\n" RESET;
			break;
		}

		switch (resolveChoice(input))
		{
			case ADD:
				std::cout << CLEAR_SCREEN
				std::cout << YELLOW "ADD" RESET " was selected: Enter a new contact.\n\n";
				ret = phonebook.AddContact();
				std::cout << CLEAR_SCREEN
				if (ret)
					std::cout << RED "EOF received. No contact added.\n\n" RESET;
				else
					std::cout << GREEN "Contact was added!\n\n" RESET;
				break;

			case SEARCH:
				std::cout << CLEAR_SCREEN
				std::cout << YELLOW "SEARCH" RESET " was selected.\n\n";
				ret = phonebook.SearchContact();
				std::cout << CLEAR_SCREEN
				if (ret)
					std::cout << RED "No contacts saved yet." RESET << std::endl << std::endl;
				else
					std::cout << GREEN "Contact was searched!" RESET << std::endl << std::endl;
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