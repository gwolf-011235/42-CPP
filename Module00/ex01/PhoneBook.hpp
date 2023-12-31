/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:16:22 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/19 16:51:03 by gwolf            ###   ########.fr       */
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

	void		Loop(void);

private:
	enum e_choice {INVALID, ADD, SEARCH, EXIT};

	Contact m_contact[NUM_CONTACTS];
	int		m_filled_contacts;

	void		PrintOptions(void);
	e_choice	ResolveChoice(const std::string& input);
	bool		AddContact(void);
	bool		SearchContact(void);
	bool		ReceiveInput(const std::string& ref, std::string& input, bool numcheck);
	bool		IsValidNumber(const std::string& number);
	std::string	Truncate(std::string str, size_t width);
	void		PrintContactTable(void);
	bool		ConvertToIndex(const std::string& input, int& index);

};

#endif