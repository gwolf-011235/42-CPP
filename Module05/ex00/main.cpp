/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:50:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 13:31:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test_ctor()
{
	std::cout << "*** Test constructor ***\n";

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

void	test_method()
{
	std::cout << "*** Test method ***\n";

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

int	main(void)
{
	test_ctor();
	test_method();

	return (0);
}
