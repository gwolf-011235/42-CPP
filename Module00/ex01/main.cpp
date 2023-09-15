/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:06:57 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/15 16:39:13 by gwolf            ###   ########.fr       */
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
	std::cout << YELLOW "ADD" RESET ": save a new contact" << std::endl;
	std::cout << YELLOW "SEARCH" RESET ": display a specific contact" << std::endl;
	std::cout << YELLOW "EXIT" RESET ": exit the program" << std::endl;
	std::cout << std::endl << "Please enter a " YELLOW "keyword: " RESET;
}


int	main(void)
{
	PhoneBook 	phonebook;
	std::string input;
	bool		loop;
	bool		ret;

	loop = true;
	std::cout << CLEAR_SCREEN
	std::cout << BOLD << BLUE << "My awesome phonebook program!" << RESET << std::endl << std::endl;
	do
	{
		printOptions();

		if (!getline(std::cin, input))
		{
			std::cout << RED "EOF received - Aborting." RESET << std::endl;
			break;
		}

		switch (resolveChoice(input))
		{
			case ADD:
				std::cout << CLEAR_SCREEN
				std::cout << YELLOW "ADD" RESET " was selected: Enter a new contact." << std::endl << std::endl;
				ret = phonebook.AddContact();
				std::cout << CLEAR_SCREEN
				if (ret)
					std::cout << RED "EOF received. No contact added." RESET << std::endl << std::endl;
				else
					std::cout << GREEN "Contact was added!" RESET << std::endl << std::endl;
				break;

			case SEARCH:
				std::cout << CLEAR_SCREEN
				std::cout << YELLOW "SEARCH" RESET " was selected." << std::endl << std::endl;
				ret = phonebook.SearchContact();
				if (ret)
					std::cout << RED "EOF received." RESET << std::endl << std::endl;
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