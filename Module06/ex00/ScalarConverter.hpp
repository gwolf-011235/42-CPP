/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:34:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/05 14:32:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <string>
# include <cstdlib>
# include <cmath>

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
