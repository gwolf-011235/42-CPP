/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:50:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 11:28:28 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

void	sign_and_execute_form(Bureaucrat &bureaucrat, AForm &form)
{
	std::cout << "\n** Attempting to sign and exectue form \n\n";
	std::cout << "* Info about bureaucrat and form \n";
	std::cout << bureaucrat;
	std::cout << form;
	std::cout << "\n";

	std::cout << "* Signing form \n";
	while (bureaucrat.getGrade() > form.getGradeToSign())
		bureaucrat.promote();
	bureaucrat.signForm(form);
	std::cout << "\n";

	std::cout << "** Executing form \n";
	while (bureaucrat.getGrade() > form.getGradeToExecute())
		bureaucrat.promote();
	bureaucrat.executeForm(form);
	std::cout << "\n";
}

int	main(void)
{
	Bureaucrat	stanley("Stanley", 150);
	Intern		intern;
	AForm		*form;

	std::cout << stanley;
	std::cout << "---------------------\n";
	std::cout << "Intern! Make me a shrubbery creation form! I want to plant trees in TheVillage\n";
	try
	{
		form = intern.makeForm("shrubbery creation", "TheVillage");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	sign_and_execute_form(stanley, *form);
	delete form;
	std::cout << "---------------------\n";
	std::cout << "Intern! Make me a robotomy request form! I want to robotomize my cat\n";
	try
	{
		form = intern.makeForm("robotomy request", "cat");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	sign_and_execute_form(stanley, *form);
	delete form;
	std::cout << "---------------------\n";
	std::cout << "Intern! Make me a presidential pardon form! I want to pardon my mother\n";
	try
	{
		form = intern.makeForm("presidential pardon", "mother");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	sign_and_execute_form(stanley, *form);
	delete form;
	std::cout << "---------------------\n";
	std::cout << "Intern! Make me a promotion form! I want to thank you for your good work\n";
	try
	{
		form = intern.makeForm("promotion", "intern");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	std::cout << "Ha! There is no such form! You don't deserve praise!\n";
	std::cout << "---------------------\n";
	return (0);
}
