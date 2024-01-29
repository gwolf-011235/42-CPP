/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:49:24 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 16:52:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// ctor

Intern::Intern(void)
{
	std::cout << "Default constructor called: Intern \n";
}

Intern::Intern(const Intern& ref)
{
	std::cout << "Copy constructor called: Intern \n";
}

Intern::~Intern(void)
{
	std::cout << "Destructor called: Intern \n";
}

// operators

Intern& Intern::operator=(const Intern& ref)
{
	std::cout << "Copy assignment operator called: Intern \n";
	return (*this);
}

// methods

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	AForm*	form = NULL;

	if (formName == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else if (formName == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else
		std::cout << "Form " << formName << " does not exist\n";
	return (form);
}
