/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:56:35 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/04 09:21:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>


void	test(void)
{
	std::cout << "TEST Correct Input\n";

	std::pair<std::string, double> tests[] = {
		std::make_pair("1 2 +", 3),
		std::make_pair("5 3 -", 2),
		std::make_pair("9 4 *", 36),
		std::make_pair("7 8 /", 7.0 / 8.0),
		std::make_pair("5 3 + 2 *", 16),
		std::make_pair("3 4 * 5 6 * +", 42),
		std::make_pair("5 2 2 * * 9 + 7 6 * -", -13)
	};

	RPN	rpn;

	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
	{
		std::cout << "Test [" << i + 1 << "]: ";
		try {
			rpn.evaluate(tests[i].first);
			double result = rpn.getResult();
			if (result != tests[i].second) {
				std::cerr << "failed! Expected: " << tests[i].second << " but got: " << result;
			} else {
				std::cout << "passed";
			}
		}
		catch (std::exception& e) {
			std::cerr << "Test [" << i + 1 << "] threw exception: " << e.what() << "\n";
		}
		std::cout << "\t'" << tests[i].first << "' = " << tests[i].second << "\n";
	}
	std::cout << "END\n\n";
}

void	test_invalid(void)
{
	std::cout << "TEST Invalid input\n";

	std::string tests[] = {
		"1 2 H",
		"12 3 +",
		"9 /",
		"2 2 2 **",
		"1 2 3 +"
	};

	RPN rpn;

	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
	{
		try {
			rpn.evaluate(tests[i]);
		}
		catch (std::exception& e) {
			std::cerr << "Test [" << i + 1 << "] threw exception: " << e.what() << "\n";
		}
	}
	std::cout << "END\n\n";
}

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"<expression>\"" << std::endl;
		return 1;
	}

	if (argc == 1)
	{
		test();
		test_invalid();
		return 0;
	}

	RPN	rpn;

	try {
		rpn.evaluate(argv[1]);
		std::cout << rpn.getResult() << "\n";
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
