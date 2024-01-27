/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:13 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/27 16:11:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

#include <iostream>
#include <stdint.h>

class Bureaucrat
{
public:

	Bureaucrat(const std::string &name = "Small_cog", uint8_t grade = 150);
	Bureaucrat(const Bureaucrat& ref);
	~Bureaucrat(void);
	Bureaucrat& operator= (const Bureaucrat& ref);

	const std::string&	getName() const;
	uint8_t				getGrade() const;

private:

	const std::string	m_name;
	uint8_t				m_grade;
};


#endif
