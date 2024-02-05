/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/05 14:50:45 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ctor

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called: ScalarConverter \n";
}

ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
	std::cout << "Copy constructor called: ScalarConverter \n";
	(void)ref;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor called: ScalarConverter \n";
}

// operators

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref)
{
	std::cout << "Copy assignment operator called: ScalarConverter \n";
	(void)ref;
	return (*this);
}

// methods

enum e_type
{
	TYPE_INVALID,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE
};

static e_type	getType(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return (TYPE_CHAR);

	char	*endptr;
	double	converted_num = strtod(str.c_str(), &endptr);

	if (str.empty() || (*endptr != '\0' && (*endptr != 'f' && str != "-inff" && str != "+inff" && str != "nanf")))
		return (TYPE_INVALID);
	if (str.find('.') == std::string::npos && converted_num <= std::numeric_limits<int>::max() && converted_num >= std::numeric_limits<int>::min())
		return (TYPE_INT);
	if (*endptr == 'f' || str == "-inff" || str == "+inff" || str == "nanf")
		return (TYPE_FLOAT);
	else
		return (TYPE_DOUBLE);
}

static const std::string&	enumToString(e_type type)
{
	static const std::string	arrayOfTypes[] = {
		"invalid",
		"char",
		"int",
		"float",
		"double"
	};

	return (arrayOfTypes[type]);
}

template <typename T>
static void	printChar(T input)
{
	if (input > std::numeric_limits<unsigned char>::max() || input < std::numeric_limits<unsigned char>::min() || isnan(input))
		std::cout << "char:\timpossible\n";
	else if (input < 32 || input > 126)
		std::cout << "char:\tNon displayable\n";
	else
		std::cout << "char:\t'" << static_cast<unsigned char>(input) << "'\n";
}

template <typename T>
static void	printInt(T input)
{
	if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min() || isnan(input))
		std::cout << "int:\timpossible\n";
	else
		std::cout << "int:\t" << static_cast<int>(input) << "\n";
}

template <typename T>
static void	printFloat(T input)
{
	if (isinf(input) || isnan(input))
		std::cout << "float:\t" << static_cast<float>(input) << "f\n";
	else if (input > std::numeric_limits<float>::max() || input < nextafterf(-std::numeric_limits<float>::infinity(), 0.0f))
		std::cout << "float:\timpossible\n";
	else
		std::cout << "float:\t" << std::fixed << static_cast<float>(input) << "f\n";
}

template <typename T>
static void	printDouble(T input)
{
	std::cout << "double:\t" << static_cast<double>(input) << "\n";
}

static void printInvalid(const std::string &str)
{
	std::cout << "The input '" << str << "' is invalid\n";
}

template <typename T>
static void printDispatch(T input)
{
	printChar(input);
	printInt(input);
	printFloat(input);
	printDouble(input);
}

static void	printInput(const std::string &str, const e_type type)
{
	switch (type)
	{
	case TYPE_CHAR:
	{
		unsigned char input_char = str[0];
		printDispatch(input_char);
		break;
	}
	case TYPE_INT:
	{
		int	input_int = std::atoi(str.c_str());
		printDispatch(input_int);
		break;
	}
	case TYPE_FLOAT:
	{
		float	input_float = std::strtof(str.c_str(), NULL);
		printDispatch(input_float);
		break;
	}
	case TYPE_DOUBLE:
	{
		double	input_double = std::strtod(str.c_str(), NULL);
		printDispatch(input_double);
		break;
	}
	default:
	{
		printInvalid(str);
		break;
	}
	}
}

void	ScalarConverter::convert(const std::string &str)
{
	std::cout << "Input:\t'" << str << "'\n";
	e_type	type = getType(str);
	std::cout << "Type:\t" << enumToString(type) << "\n\n";
	std::cout << "Value as\n";
	printInput(str, type);
}
