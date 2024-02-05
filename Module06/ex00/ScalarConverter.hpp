/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:34:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/05 15:56:06 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <string>
# include <cstdlib>
# include <cmath>
# include <cstring>

class ScalarConverter
{
public:
	static void	convert(const std::string &str);
private:
// ctor
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& ref);
	~ScalarConverter(void);
// operator
	ScalarConverter& operator= (const ScalarConverter& ref);
};

#endif
