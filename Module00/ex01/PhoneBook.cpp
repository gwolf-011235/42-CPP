/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:23:43 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/15 12:17:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

PhoneBook::PhoneBook(void)
{
	m_filled_contacts = 0;
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
	std::string 			input[5];
	static unsigned char	index;

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

	m_contact[index].SetInfo(input[0], input[1], input[2], input[3], input[4]);
	if (m_filled_contacts < NUM_CONTACTS)
		m_filled_contacts++;
	index++;
	if (index >= NUM_CONTACTS)
		index = 0;
	return (false);
}

std::string&	PhoneBook::Truncate(std::string& str, size_t width)
{
	if (str.length() > width)
	{
		str.resize(width - 1);
		return (str.append("."));
	}
	return (str);
}
bool	PhoneBook::SearchContact(void)
{
	std::string temp[3];
	for (int i = 0; i < m_filled_contacts; i++)
	{
		m_contact[i].GetFirstName(temp[0]);
		m_contact[i].GetLastName(temp[1]);
		m_contact[i].GetNickName(temp[2]);
		std::cout << std::setw(10) << Truncate(temp[0], 10) << "|";
		std::cout << std::setw(10) << Truncate(temp[1], 10) << "|";
		std::cout << std::setw(10) << Truncate(temp[2], 10) << "|" << std::endl;
	}
	return (false);
}