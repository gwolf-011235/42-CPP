/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:07 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/27 16:20:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, uint8_t grade) :
	m_name(name), m_grade(grade)
{
	std::cout << "Default constructor called: Bureaucrat \n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) :
	m_name(ref.getName()), m_grade(ref.getGrade())
{
	std::cout << "Copy constructor called: Bureaucrat \n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::cout << "Copy assignment operator called: Bureaucrat \n";
	m_grade = ref.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called: Bureaucrat \n";
}

const std::string&	Bureaucrat::getName() const;
{
	return (this->m_name);
}

uint8_t	Bureaucrat::getGrade() const;
{
	return (this->m_grade);
}
