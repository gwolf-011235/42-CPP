/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:34:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/03 17:01:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <string>
# include <cstdlib>

class ScalarConverter
{
public:
	static void	convert(const std::string &str);
private:
	enum e_type
	{
		TYPE_INVALID,
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE
	};
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& ref);
	~ScalarConverter(void);
	ScalarConverter& operator= (const ScalarConverter& ref);
	static e_type	getType(const std::string &str);
};


#endif
