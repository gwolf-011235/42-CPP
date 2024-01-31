/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:55:07 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 10:59:38 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	if (this != &ref) {
		m_grade = ref.getGrade();
	}
	return (*this);
}

// exception

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg) :
	std::runtime_error(msg)
{
	std::cout << "Constructor called: Bureaucrat::GradeTooHighException \n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg) :
	std::runtime_error(msg)
{
	std::cout << "Constructor called: Bureaucrat::GradeTooLowException\n";
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

void	Bureaucrat::signForm(Form &form) const
{
	if (form.getIsSigned() == true)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because it is already signed\n";
		return ;
	}
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << getName() << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
	}
}

// stream operators

std::ostream &operator<<(std::ostream &o, const Bureaucrat &c)
{
	o << c.getName() << ", bureaucrat grade " << c.getGrade() << ".\n";
	return o;
}
