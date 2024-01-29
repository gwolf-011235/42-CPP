/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:19:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 15:58:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ctor

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("ShrubberyCreationForm", 145, 137), m_target(target + "_shrubbery")
{
	std::cout << "Default constructor called: ShrubberyCreationForm \n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) :
	AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	std::cout << "Copy constructor called: ShrubberyCreationForm \n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called: ShrubberyCreationForm \n";
}

// operators

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	std::cout << "Copy assignment operator called: ShrubberyCreationForm \n";
	if (this != &ref) {
		// Cannot copy, type is const
	}
	return (*this);
}

// methods

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::ofstream file;
	file.open(m_target.c_str());
	file << "      _-_\n"
			"   /~~   ~~\\\n"
			" /~~         ~~\\\n"
			"{               }\n"
			" \\  _-     -_  /\n"
			"   ~  \\\\ //  ~\n"
			"_- -   | | _- _\n"
			"  _ -  | |   -_\n"
			"      // \\\\\n";
	file.close();
}
