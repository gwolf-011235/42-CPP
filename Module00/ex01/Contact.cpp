/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:25:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/15 11:46:54by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::SetInfo(std::string& first_name, std::string& last_name, std::string& nick_name,
						std::string& phonenumber, std::string& darkest_secret)
{
	m_first_name = first_name;
	m_last_name = last_name;
	m_nick_name = nick_name;
	m_phone_number = phonenumber;
	m_darkest_secret = darkest_secret;
}

std::string	Contact::GetFirstName(void)
{
	return m_first_name;
}

std::string	Contact::GetLastName(void)
{
	return m_last_name;
}

std::string	Contact::GetNickName(void)
{
	return m_nick_name;
}

std::string	Contact::GetPhonenumber(void)
{
	return m_phone_number;
}

std::string	Contact::GetDarkestSecret(void)
{
	return m_darkest_secret;
}

void	Contact::PrintInfo(void)
{
	std::cout << "First name: " << m_first_name << "\n";
	std::cout << "Last name: " << m_last_name << "\n";
	std::cout << "Nickname: " << m_nick_name << "\n";
	std::cout << "Phonenumber: " << m_phone_number << "\n";
	std::cout << "Darkest secret: " << m_darkest_secret << std::endl;
}