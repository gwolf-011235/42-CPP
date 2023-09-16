/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:23:43 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/16 19:53:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>
#include <sstream>

PhoneBook::PhoneBook(void)
{
	m_filled_contacts = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::Loop(void)
{
	std::string input;
	bool		loop;
	bool		ret;

	loop = true;
	std::cout << CLEAR_SCREEN
	std::cout << BOLD << BLUE << "My awesome phonebook!\n\n" << RESET;
	do
	{
		PrintOptions();

		if (!getline(std::cin, input))
		{
			std::cout << RED "EOF received - Aborting.\n" RESET;
			break;
		}
		std::cout << CLEAR_SCREEN
		switch (ResolveChoice(input))
		{
			case ADD:
				std::cout << YELLOW "ADD" RESET " was selected. Press Ctrl+D to abort.\n\n";
				ret = AddContact();
				std::cout << CLEAR_SCREEN
				if (ret)
					std::cout << RED "EOF received. No contact added.\n\n" RESET;
				else
					std::cout << GREEN "Contact was added!\n\n" RESET;
				break;

			case SEARCH:
				if (m_filled_contacts == 0)
				{
					std::cout << RED "No contacts saved yet.\n\n" RESET;
					break;
				}
				std::cout << YELLOW "SEARCH" RESET " was selected. Press Ctrl+D to abort.\n\n";
				ret = SearchContact();
				std::cout << CLEAR_SCREEN
				if (ret)
					std::cout << RED "EOF received. No contact searched.\n\n" RESET;
				else
					std::cout << GREEN "Contact was searched!\n\n" RESET;
				break;

			case EXIT:
				std::cout << YELLOW "EXIT" RESET " was selected.\n\n";
				std::cout << GREEN "Goodbye" RESET " 👋\n" << std::endl;
				loop = false;
				break;

			default:
				std::cout << RED "\"" << input << "\": Not recognised\n\n" RESET;
				break;
		}
	} while (loop);
}

void	PhoneBook::PrintOptions(void)
{
	std::cout << YELLOW "ADD" RESET ": save a new contact\n";
	std::cout << YELLOW "SEARCH" RESET ": display a specific contact\n";
	std::cout << YELLOW "EXIT" RESET ": exit the program\n";
	std::cout << "\n\nPlease enter a " YELLOW "keyword" RESET ": ";
}

PhoneBook::e_choice PhoneBook::ResolveChoice(std::string input)
{
	if (input == "ADD") return ADD;
	else if (input == "SEARCH") return SEARCH;
	else if (input == "EXIT") return EXIT;
	else return INVALID;
}

bool	PhoneBook::IsValidNumber(const std::string& number)
{
	for(int i = 0; i < (int)number.length(); i++)
	{
		if (number[i] > '9' || number[i] < '0')
			return false;
	}
	return true;
}

int		PhoneBook::ReceiveInput(const std::string& ref, std::string& input, bool numcheck = false)
{
	while (true)
	{
		std::cout << "Please enter " << ref << ": ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			std::clearerr(stdin);
			return (-1);
		}
		if (input.empty() || input.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			std::cout << "Should not be empty!" << std::endl;
		else if (numcheck && !IsValidNumber(input))
			std::cout << "Only numbers are allowed!" << std::endl;
		else
			return (0);
	}
}

bool	PhoneBook::AddContact(void)
{
	std::string 			input[5];
	static unsigned char	index;

	if (ReceiveInput("first name", input[0]))
		return (true);
	if (ReceiveInput("last name", input[1]))
		return (true);
	if (ReceiveInput("nick name", input[2]))
		return (true);
	if (ReceiveInput("phone number", input[3], true))
		return (true);
	if (ReceiveInput("darkest secret", input[4]))
		return (true);

	m_contact[index].SetInfo(input[0], input[1], input[2], input[3], input[4]);
	if (m_filled_contacts < NUM_CONTACTS)
		m_filled_contacts++;
	index++;
	if (index >= NUM_CONTACTS)
		index = 0;
	return (false);
}

std::string	PhoneBook::Truncate(std::string str, size_t width)
{
	if (str.length() > width)
	{
		str.resize(width - 1);
		return (str.append("."));
	}
	return (str);
}

void	PhoneBook::PrintContactTable(void)
{
	std::cout << "|";
	std::cout << "Index     |";
	std::cout << "First Name|";
	std::cout << "Last Name |";
	std::cout << "Nickname  |" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << "|" << std::setw(11) << std::setfill('-');
	std::cout << "|" << std::setfill(' ') << RESET << std::endl;
	for (int i = 0; i < m_filled_contacts; i++)
	{
		std::string temp;
		if (i % 2)
			temp = B_WHITE;
		else
			temp = B_CYAN;
		std::cout << "|" << BLACK;
		std::cout << temp << std::setw(10) << i << "|";
		std::cout << temp << std::setw(10) << Truncate(m_contact[i].GetFirstName(), 10) << "|";
		std::cout << temp << std::setw(10) << Truncate(m_contact[i].GetLastName(), 10) << "|";
		std::cout << temp << std::setw(10) << Truncate(m_contact[i].GetNickName(), 10) << RESET << "|" << std::endl;
	}
	std::cout << RESET << std::endl;
}

bool	PhoneBook::SearchContact(void)
{
	std::string	input;
	int index;

	PrintContactTable();
	do {
		if (ReceiveInput("the index of the contact you want to see", input, true))
			return true;
	} while (ConvertToIndex(input, index));
	m_contact[index].PrintInfo();
	std::cout << "Press Enter to continue...";
	while (std::cin.get()!='\n')
	{
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
			break;
		}
	}
	return (false);
}

bool	PhoneBook::ConvertToIndex(std::string& input, int& index)
{
	std::stringstream ss(input);

	if (!(ss >> index) || index < 0 || index >= m_filled_contacts)
	{
		if (m_filled_contacts == 1)
			std::cout << "Invalid input. Please enter 0.\n";
		else
			std::cout << "Invalid input. Please enter a number between 0 and " << m_filled_contacts << ".\n";
		return true;
	}
	else
	{
		std::cout << "You selected contact #" << index << ": " << std::endl;
	}
	return false;
}
