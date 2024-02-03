/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/03 17:00:29 by gwolf            ###   ########.fr       */
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
	(void)ref;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref)
{
	std::cout << "Copy assignment operator called: ScalarConverter \n";
	(void)ref;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor called: ScalarConverter \n";
}

ScalarConverter::e_type	ScalarConverter::getType(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (TYPE_CHAR);

	char	*endptr;
	double	converted_num = strtod(str.c_str(), &endptr);

	if (str.empty() || (*endptr != '\0' && *(endptr + 1) != 'f') || str != "-inff" || str != "+inff" || str != "nanf")
		return (TYPE_INVALID);
	if (str.find('.') == std::string::npos && converted_num <= std::numeric_limits<int>::max() && converted_num >= std::numeric_limits<int>::min())
		return (TYPE_INT);
	if (*endptr == 'f' || str == "-inff" || str == "+inff" || str == "nanf")
		return (TYPE_FLOAT);
	else
		return (TYPE_DOUBLE);
}

void	ScalarConverter::convert(const std::string &str)
{
	std::cout << "Convert: " << str << "\n";
	e_type	type = getType(str);
	std::cout << "Type: " << type << "\n";
}
