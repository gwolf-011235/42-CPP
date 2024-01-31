/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:37:56 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 11:08:33 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_H
# define AFORM_CLASS_H

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
public:
// ctor
	AForm(const std::string &name = "Standard", int gradeToSign = 150, int gradeToExecute = 150);
	AForm(const AForm& ref);
	virtual ~AForm(void);
// operators
	AForm& operator= (const AForm& ref);
// exception
	class GradeTooHighException : public std::runtime_error
	{
		public:
			GradeTooHighException(const std::string &msg = "Grade is too high");
	};
	class GradeTooLowException : public std::runtime_error
	{
		public:
			GradeTooLowException(const std::string &msg = "Grade is too low");
	};
	class FormNotSigned : public std::runtime_error
	{
		public:
			FormNotSigned(const std::string &msg = "Form is not signed");
	};
	class FormAlreadySigned : public std::runtime_error
	{
		public:
			FormAlreadySigned(const std::string &msg = "Form is already signed");
	};
// getters
	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
// methods
	void			beSigned(const Bureaucrat& ref);
	virtual void	execute(const Bureaucrat& executor) const;

private:
// attributes
	const std::string	m_name;
	bool				m_isSigned;
	const int			m_gradeToSign;
	const int			m_gradeToExecute;
};

// stream operators

std::ostream &operator<<(std::ostream &o, const AForm &c);

#endif
