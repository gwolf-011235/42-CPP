/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:07 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 10:46:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ctor

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	m_name(name), m_grade(grade)
{
	std::cout << "Default constructor called: Bureaucrat \n";
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) :
	m_name(ref.getName()), m_grade(ref.getGrade())
{
	std::cout << "Copy constructor called: Bureaucrat \n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called: Bureaucrat \n";
}

// operators

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
	std::cout << "Copy assignment operator called: Bureaucrat \n";
	m_grade = ref.getGrade();
	return (*this);
}

// exception

Bureaucrat::GradeTooHighException::GradeTooHighException() :
	std::runtime_error("Grade is too high")
{
	std::cout << "Constructor called: GradeTooHighException \n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() :
	std::runtime_error("Grade is too low")
{
	std::cout << "Constructor called: GradeTooLowException\n";
}

// getters

const std::string&	Bureaucrat::getName() const
{
	return (this->m_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->m_grade);
}

// methods

void	Bureaucrat::promote()
{
	if (m_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		m_grade--;
	std::cout << "Bureaucrat " << getName() << " was promoted to grade " << getGrade() << "\n";
}

void	Bureaucrat::demote()
{
	if (m_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		m_grade++;
	std::cout << "Bureaucrat " << getName() << " was demoted to grade " << getGrade() << "\n";
}

// stream operator

std::ostream &operator<<(std::ostream &o, const Bureaucrat &c)
{
	o << c.getName() << ", bureaucrat grade " << c.getGrade() << ".\n";
	return o;
}
