/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:16:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/15 12:02:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

# define NUM_CONTACTS 8

class PhoneBook
{
public:
	PhoneBook( void );
	~PhoneBook( void );

	bool	AddContact(void);
	bool	SearchContact(void);

private:
	Contact m_contact[NUM_CONTACTS];
	int		m_filled_contacts;

	int				ReceiveInput(const std::string& ref, std::string& input);
	std::string&	Truncate(std::string& str, size_t width);

};

#endif