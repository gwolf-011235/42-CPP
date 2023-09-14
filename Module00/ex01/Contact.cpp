/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:25:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/11 09:21:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::SetInfo(std::string info[5])
{
	first_name = info[0];
	last_name = info[1];
	nick_name = info[2];
	phone_number = info[3];
	darkest_secret = info[4];
}