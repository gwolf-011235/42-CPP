/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:49:24 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 00:58:32 by gwolf            ###   ########.fr       */
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
	(void)ref;
}

Intern::~Intern(void)
{
	std::cout << "Destructor called: Intern \n";
}

// operators

Intern& Intern::operator=(const Intern& ref)
{
	std::cout << "Copy assignment operator called: Intern \n";
	(void)ref;
	return (*this);
}

// methods

AForm*	Intern::createShrubberyCreationForm(const std::string& target) const
{
	std::cout << "Creating shrubbery creation form with target: " << target << "\n";
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomyRequestForm(const std::string& target) const
{
	std::cout << "Creating robotomy request form with target: " << target << "\n";
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidentialPardonForm(const std::string& target) const
{
	std::cout << "Creating presidential pardon form with target: " << target << "\n";
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	static const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	static const FormCreationFunc formCreators[3] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; ++i) {
		if (formNames[i] == formName)
			return ((this->*formCreators[i])(target));
	}
	std::cout << "Form " << formName << " does not exist\n";
	return (NULL);
}
