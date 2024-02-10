/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:08:31 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/10 13:31:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

//ctor

Data::Data(int id, std::string name, std::string description, int count) :
	id(id), name(name), description(description), count(count)
{
	return ;
}

Data::Data(const Data& ref)
{
	*this = ref;
}

Data::~Data()
{
	return ;
}

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

void	Data::printData(void)
{
	std::cout << "id:\t\t" << id << "\n";
	std::cout << "name:\t\t" << name << "\n";
	std::cout << "description:\t" << description << "\n";
	std::cout << "count:\t\t" << count << "\n";
}
