/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:06:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/05 16:06:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Serializer
{
public:
	Serializer(void);
	Serializer(const Serializer& ref);
	~Serializer(void);
	Serializer& operator= (const Serializer& ref);
private:
	/* private stuff */
};

#include "Serializer"

Serializer::Serializer(void)
{
	std::cout << "Default constructor called: Serializer \n";
}

Serializer::Serializer(const Serializer& ref)
{
	std::cout << "Copy constructor called: Serializer \n";
}

Serializer& Serializer::operator=(const Serializer& ref)
{
	std::cout << "Copy assignment operator called: Serializer \n";
}

Serializer::~Serializer(void)
{
	std::cout << "Destructor called: Serializer \n";
}
