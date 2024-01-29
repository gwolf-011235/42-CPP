/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:13 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 15:43:51 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat
{
public:
//ctor
	Bureaucrat(const std::string &name = "Small_cog", int grade = 150);
	Bureaucrat(const Bureaucrat& ref);
	~Bureaucrat();
//operators
	Bureaucrat& operator= (const Bureaucrat& ref);
//getters
	const std::string&	getName() const;
	int					getGrade() const;
//exception
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
//methods
	void	promote();
	void	demote();
	void	signForm(AForm &form) const;
	void	executeForm(AForm const &form) const;
private:

	const std::string	m_name;
	int					m_grade;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &c);

#endif
