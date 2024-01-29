/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:50:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 15:06:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iosfwd>

void	test_bureaucrat_ctor()
{
	std::cout << "*** Test Bureaucrat constructor ***\n";

	try {
		Bureaucrat	tooHigh("tooHigh", 0);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bureaucrat	tooLow("tooLow", 151);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Bureaucrat	MrHigh("MrHigh", 1);
	Bureaucrat	MrLow("MrLow", 150);
	Bureaucrat	MrCopy(MrHigh);
	Bureaucrat	MrAssign;

	MrAssign = MrLow;
	std::cout << MrHigh;
	std::cout << MrLow;
	std::cout << MrCopy;
	std::cout << MrAssign;
}

void	test_bureaucrat_method()
{
	std::cout << "*** Test Bureaucrat method ***\n";

	Bureaucrat	stanley("stanley", 10);
	std::cout << stanley;
	while (1)
	{
		try {
			stanley.promote();
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
			break ;
		}
	}
	std::cout << stanley;

	Bureaucrat	steven("steven", 140);
	std::cout << steven;
	while (1)
	{
		try {
			steven.demote();
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
			break ;
		}
	}
	std::cout << steven;
}

void	test_form_ctor()
{
	std::cout << "*** Test Form constructor ***\n";

	try {
		Form	tooHigh("tooHigh", 0, 12);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Form	tooLow("tooLow", 150, 151);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Form	special("Special", 1, 1);
	Form	random("Random", 100, 100);
	Form	copy(special);
	Form	assignment;

	assignment = random;
	std::cout << special;
	std::cout << random;
	std::cout << copy;
	std::cout << assignment;
}

void	test_sign_form()
{
	std::cout << "*** Test Sign Form ***\n";

	Bureaucrat	stanley("Stanley", 90);
	Bureaucrat	steven("Steven", 10);
	Form		special("Special", 10, 10);
	Form		random("Random", 100, 100);

	std::cout << stanley;
	std::cout << steven;
	std::cout << special;
	std::cout << random;
	std::cout << "\n";

	std::cout << "Stanley tries to sign Special and Random\n";
	stanley.signForm(special);
	stanley.signForm(random);
	std::cout << "\n";

	std::cout << "Steven tries to sign Special and Random\n";
	steven.signForm(special);
	steven.signForm(random);
	std::cout << "\n";

	std::cout << special;
	std::cout << random;
}

int	main(void)
{
	//test_bureaucrat_ctor();
	//test_bureaucrat_method();
	//test_form_ctor();
	test_sign_form();
	return (0);
}
