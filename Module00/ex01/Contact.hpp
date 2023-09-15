/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:25:58 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/15 17:51:40 by gwolf            ###   ########.fr       */
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
	void		SetInfo(std::string& first_name, std::string& last_name,
						std::string& nick_name, std::string& phonenumber,
						std::string& darkest_secret);
	std::string	GetFirstName(void);
	std::string	GetLastName(void);
	std::string	GetNickName(void);
	std::string	GetPhonenumber(void);
	std::string	GetDarkestSecret(void);
};

#endif