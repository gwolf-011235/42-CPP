/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:25:58 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/15 12:08:06 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nick_name;
	std::string m_phone_number;
	std::string m_darkest_secret;

public:
	Contact(void);
	~Contact(void);
	void	SetInfo(std::string& first_name, std::string& last_name,
					std::string& nick_name, std::string& phonenumber,
					std::string& darkest_secret);
	void	GetFirstName(std::string& first_name);
	void	GetLastName(std::string& last_name);
	void	GetNickName(std::string& nick_name);
	void	GetPhonenumber(std::string& phonenumber);
	void	GetDarkestSecret(std::string& darkest_secret);
};

#endif