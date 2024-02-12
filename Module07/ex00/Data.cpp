/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:08:31 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 15:57:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

//operator

Data&	Data::operator= (const Data& ref)
{
	if (this == &ref)
		return *this;
	id = ref.id;
	name = ref.name;
	description = ref.description;
	count = ref.count;
	return *this;
}

bool	Data::operator< (const Data& ref) const
{
	return id < ref.id;
}

bool	Data::operator> (const Data& ref) const
{
	return ref < *this;
}

std::ostream& operator<< (std::ostream& os, const Data& ref)
{
	os << "id:\t\t" << ref.id << "\n";
	os << "name:\t\t" << ref.name << "\n";
	os << "description:\t" << ref.description << "\n";
	os << "count:\t\t" << ref.count << "\n\n";
	return os;
}
