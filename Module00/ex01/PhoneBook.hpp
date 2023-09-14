/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:16:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/14 13:48:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook( void );
	~PhoneBook( void );
	bool AddContact(void);

private:
	Contact m_contact[8];
	int	ReceiveInput(const std::string& ref, std::string& input);

};

#endif