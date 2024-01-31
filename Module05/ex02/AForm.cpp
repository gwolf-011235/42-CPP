/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:38:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 11:09:21 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ctor

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) :
	m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute)
{
	std::cout << "Default constructor called: AForm \n";
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException("Grade to sign is too high");
	else if (gradeToExecute < 1)
		throw AForm::GradeTooHighException("Grade to execute is too high");
	else if (gradeToSign > 150)
		throw AForm::GradeTooLowException("Grade to sign is too low");
	else if (gradeToExecute > 150)
		throw AForm::GradeTooLowException("Grade to execute is too low");
}

AForm::AForm(const AForm& ref) :
	m_name(ref.getName()), m_isSigned(false), m_gradeToSign(ref.getGradeToSign()), m_gradeToExecute(ref.getGradeToExecute())
{
	std::cout << "Copy constructor called: AForm \n";
}

AForm::~AForm(void)
{
	std::cout << "Destructor called: AForm \n";
}

// operators

AForm& AForm::operator=(const AForm& ref)
{
	std::cout << "Copy assignment operator called: AForm \n";
	if (this != &ref) {
		m_isSigned = ref.getIsSigned();
	}
	return (*this);
}

// exception

AForm::GradeTooHighException::GradeTooHighException(const std::string &msg) :
	std::runtime_error(msg)
{
	std::cout << "Constructor called: AForm::GradeTooHighException \n";
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &msg) :
	std::runtime_error(msg)
{
	std::cout << "Constructor called: AForm::GradeTooLowException\n";
}

AForm::FormNotSigned::FormNotSigned(const std::string &msg) :
	std::runtime_error(msg)
{
	std::cout << "Constructor called: AForm::FormNotSigned\n";
};

AForm::FormAlreadySigned::FormAlreadySigned(const std::string &msg) :
	std::runtime_error(msg)
{
	std::cout << "Constructor called: AForm::FormAlreadySigned\n";
};

// getters

const std::string&	AForm::getName() const
{
	return (m_name);
}

bool	AForm::getIsSigned() const
{
	return (m_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (m_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (m_gradeToExecute);
}

// methods

void	AForm::beSigned(const Bureaucrat& ref)
{
	if (m_isSigned == true)
		throw AForm::FormAlreadySigned("Form is already signed");
	else if (ref.getGrade() > m_gradeToSign)
		throw AForm::GradeTooLowException("Bureaucrat grade is too low");
	else
		m_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (getIsSigned() == false)
		throw AForm::FormNotSigned();
	else if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException("Bureaucrat grade is too low");
}

// stream operators

std::ostream &operator<<(std::ostream &o, const AForm &c)
{
	o << "AForm: " << c.getName() << "\t| is signed: " << std::boolalpha << c.getIsSigned() << "\t| Grade to sign: " << c.getGradeToSign() << "\t| Grade to exec: " << c.getGradeToExecute() << "\n";
	return o;
}
