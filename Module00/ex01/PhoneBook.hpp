/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:16:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/16 09:29:33 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# include "colors.hpp"

# define NUM_CONTACTS 8

class PhoneBook
{
public:
	PhoneBook( void );
	~PhoneBook( void );

private:
	enum e_choice {INVALID, ADD, SEARCH, EXIT};

	Contact m_contact[NUM_CONTACTS];
	int		m_filled_contacts;

	void		Loop(void);
	void		PrintOptions(void);
	e_choice	ResolveChoice(std::string input);
	bool	AddContact(void);
	bool	SearchContact(void);
	int				ReceiveInput(const std::string& ref, std::string& input, bool numcheck);
	bool			IsValidNumber(const std::string& number);
	std::string		Truncate(std::string str, size_t width);
	void			PrintContactTable(void);

};

#endif