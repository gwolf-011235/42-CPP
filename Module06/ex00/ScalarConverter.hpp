/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:34:50 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 13:42:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
public:
	static void	convert(const std::string &str) const;
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& ref);
	~ScalarConverter(void);
	ScalarConverter& operator= (const ScalarConverter& ref);
	/* private stuff */
};

#endif
