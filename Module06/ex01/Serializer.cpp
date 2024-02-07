/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:08 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/07 14:03:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Default constructor called: Serializer \n";
}

Serializer::Serializer(const Serializer& ref)
{
	std::cout << "Copy constructor called: Serializer \n";
	(void)ref;
}

Serializer::~Serializer(void)
{
	std::cout << "Destructor called: Serializer \n";
}

Serializer& Serializer::operator=(const Serializer& ref)
{
	std::cout << "Copy assignment operator called: Serializer \n";
	(void)ref;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
