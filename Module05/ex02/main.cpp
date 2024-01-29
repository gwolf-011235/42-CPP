/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:50:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 16:43:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test_ShrubberyCreationForm(Bureaucrat &bureaucrat)
{
	std::cout << "**********\n";
	std::cout << "Testing ShrubberyCreationForm \n\n";

	ShrubberyCreationForm	shrubberyCreationForm("TheVillage");

	std::cout << bureaucrat;
	std::cout << shrubberyCreationForm;
	std::cout << "---------------------\n";

	std::cout << "** Execute not signed form \n";
	bureaucrat.executeForm(shrubberyCreationForm);

	std::cout << "** Signing form \n";
	bureaucrat.signForm(shrubberyCreationForm);
	while (bureaucrat.getGrade() > shrubberyCreationForm.getGradeToSign())
		bureaucrat.promote();
	bureaucrat.signForm(shrubberyCreationForm);
	std::cout << "---------------------\n";

	std::cout << "** Executing form \n";
	bureaucrat.executeForm(shrubberyCreationForm);
	while (bureaucrat.getGrade() > shrubberyCreationForm.getGradeToExecute())
		bureaucrat.promote();
	bureaucrat.executeForm(shrubberyCreationForm);
	std::cout << "---------------------\n";
}

void	test_RobotomyRequestForm(Bureaucrat &bureaucrat)
{
	std::cout << "**********\n";
	std::cout << "Testing RobotomyRequestForm \n\n";

	srand(time(0));
	RobotomyRequestForm	robotomyRequestForm("TheVillage");

	std::cout << bureaucrat;
	std::cout << robotomyRequestForm;
	std::cout << "---------------------\n";

	std::cout << "** Signing form \n";
	while (bureaucrat.getGrade() > robotomyRequestForm.getGradeToSign())
		bureaucrat.promote();
	bureaucrat.signForm(robotomyRequestForm);
	std::cout << "---------------------\n";

	std::cout << "** Executing form \n";
	bureaucrat.executeForm(robotomyRequestForm);
	while (bureaucrat.getGrade() > robotomyRequestForm.getGradeToExecute())
		bureaucrat.promote();
	bureaucrat.executeForm(robotomyRequestForm);
	std::cout << "---------------------\n";
}

void	test_PresidentialPardonForm(Bureaucrat &bureaucrat)
{
	std::cout << "**********\n";
	std::cout << "Testing PresidentialPardonForm \n\n";

	PresidentialPardonForm	presidentialPardonForm("TheVillage");

	std::cout << bureaucrat;
	std::cout << presidentialPardonForm;
	std::cout << "---------------------\n";

	std::cout << "** Signing form \n";
	while (bureaucrat.getGrade() > presidentialPardonForm.getGradeToSign())
		bureaucrat.promote();
	bureaucrat.signForm(presidentialPardonForm);
	std::cout << "---------------------\n";

	std::cout << "** Executing form \n";
	while (bureaucrat.getGrade() > presidentialPardonForm.getGradeToExecute())
		bureaucrat.promote();
	bureaucrat.executeForm(presidentialPardonForm);
	std::cout << "---------------------\n";
}

int	main(void)
{
	Bureaucrat stanley("Stanley", 150);
	test_ShrubberyCreationForm(stanley);
	std::cout << "\n\n";
	test_RobotomyRequestForm(stanley);
	std::cout << "\n\n";
	test_PresidentialPardonForm(stanley);
	return (0);
}
