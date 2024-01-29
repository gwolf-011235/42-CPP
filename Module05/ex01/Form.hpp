/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:37:56 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 14:52:00 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_H
# define FORM_CLASS_H

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
public:
// ctor
	Form(const std::string &name = "Standard", int gradeToSign = 150, int gradeToExecute = 150);
	Form(const Form& ref);
	~Form(void);
// operators
	Form& operator= (const Form& ref);
// getters
	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
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
// methods
	void	beSigned(const Bureaucrat& ref);
private:
	const std::string	m_name;
	bool				m_isSigned;
	const int			m_gradeToSign;
	const int			m_gradeToExecute;
};

std::ostream &operator<<(std::ostream &o, const Form &c);

#endif
