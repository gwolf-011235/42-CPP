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

void	Contact::GetFirstName(std::string& first_name)
{
	first_name = m_first_name;
}

void	Contact::GetLastName(std::string& last_name)
{
	last_name = m_last_name;
}

void	Contact::GetNickName(std::string& nick_name)
{
	nick_name = m_nick_name;
}

void	Contact::GetPhonenumber(std::string& phonenumber)
{
	phonenumber = m_phone_number;
}

void	Contact::GetDarkestSecret(std::string& darkest_secret)
{
	darkest_secret = m_darkest_secret;
}