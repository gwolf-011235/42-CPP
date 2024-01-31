/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 13:42:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called: ScalarConverter \n";
}

ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
	std::cout << "Copy constructor called: ScalarConverter \n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref)
{
	std::cout << "Copy assignment operator called: ScalarConverter \n";
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor called: ScalarConverter \n";
}

void	ScalarConverter::convert(const std::string &str) const
{

}