/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:38:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 15:05:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// ctor

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) :
	m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute)
{
	std::cout << "Default constructor called: Form \n";
	if (gradeToSign < 1)
		throw Form::GradeTooHighException("Grade to sign is too high");
	else if (gradeToExecute < 1)
		throw Form::GradeTooHighException("Grade to execute is too high");
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException("Grade to sign is too low");
	else if (gradeToExecute > 150)
		throw Form::GradeTooLowException("Grade to execute is too low");
}

Form::Form(const Form& ref) :
	m_name(ref.getName()), m_isSigned(false), m_gradeToSign(ref.getGradeToSign()), m_gradeToExecute(ref.getGradeToExecute())
{
	std::cout << "Copy constructor called: Form \n";
}

Form::~Form(void)
{
	std::cout << "Destructor called: Form \n";
}

// operators

Form& Form::operator=(const Form& ref)
{
	std::cout << "Copy assignment operator called: Form \n";
	if (this != &ref) {
		m_isSigned = ref.getIsSigned();
	}
	return (*this);
}

// getters

const std::string&	Form::getName() const
{
	return (m_name);
}

bool	Form::getIsSigned() const
{
	return (m_isSigned);
}

int	Form::getGradeToSign() const
{
	return (m_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (m_gradeToExecute);
}

// exception

Form::GradeTooHighException::GradeTooHighException(const std::string &msg) :
	std::runtime_error(msg)
{
	std::cout << "Constructor called: Form::GradeTooHighException \n";
}

Form::GradeTooLowException::GradeTooLowException(const std::string &msg) :
	std::runtime_error(msg)
{
	std::cout << "Constructor called: Form::GradeTooLowException\n";
}

// methods

void	Form::beSigned(const Bureaucrat& ref)
{
	if (ref.getGrade() > m_gradeToSign)
		throw Form::GradeTooLowException("Bureaucrat grade is too low");
	else
		m_isSigned = true;
}

std::ostream &operator<<(std::ostream &o, const Form &c)
{
	o << "Form: " << c.getName() << "\t| is signed: " << std::boolalpha << c.getIsSigned() << "\t| Grade to sign: " << c.getGradeToSign() << "\t| Grade to exec: " << c.getGradeToExecute() << "\n";
	return o;
}
