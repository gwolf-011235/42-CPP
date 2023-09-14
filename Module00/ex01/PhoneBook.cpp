/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:23:43 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/14 09:38:43 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::AddContact(void)
{
	std::string input[5];

	do
	{
		std::cout << "Please enter first name: ";
		std::getline(std::cin, input[0]);
		if (std::cin.eof())
			continue;
		if (input[0].empty())
			std::cout << "Should not be empty!" << std::endl;
	} while (input[0].empty());


	std::cout << "Please enter last name: ";
	std::cin >> input[1];
	std::cout << "Please enter nick name: ";
	std::cin >> input[2];
	std::cout << "Please enter phone number: ";
	std::cin >> input[3];
	std::cout << "Please enter darkest secret: ";
	std::cin >> input[4];
	contact[0].SetInfo(input);


}