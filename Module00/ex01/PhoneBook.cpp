/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:23:43 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/14 19:19:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

int		PhoneBook::ReceiveInput(const std::string& ref, std::string& input)
{
	while (true)
	{
		std::cout << "Please enter " << ref << ": ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << "EOF received. Aborting." << std::endl;
			return (-1);
		}
		if (input.empty() || input.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			std::cout << "Should not be empty!" << std::endl;
		else
			return (0);
	}
}

bool	PhoneBook::AddContact(void)
{
	std::string input[5];

	if (ReceiveInput("first name", input[0]))
		return (true);
	if (ReceiveInput("last name", input[1]))
		return (true);
	if (ReceiveInput("nick name", input[2]))
		return (true);
	if (ReceiveInput("phone number", input[3]))
		return (true);
	if (ReceiveInput("darkest secret", input[4]))
		return (true);
	m_contact[0].SetInfo(input);
	return (false);
}