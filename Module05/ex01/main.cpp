/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:50:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 11:05:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test_form_ctor()
{
	std::cout << "*** Test Form constructor ***\n";

	try {
		Form	signTooHigh("signTooHigh", 0, 12);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Form	signTooLow("signTooLow", 170, 12);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Form	execTooHigh("execTooHigh", 12, -1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Form	execTooLow("execTooLow", 150, 161);
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
	test_form_ctor();
	test_sign_form();
	return (0);
}
