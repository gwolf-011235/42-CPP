/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:56:35 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/03 09:06:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>


void	test(void)
{
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
		try {
			rpn.evaluate(tests[i].first);
			double result = rpn.getResult();
			if (result != tests[i].second) {
				std::cerr << "Test [" << i + 1 << "] failed: '" << tests[i].first << "' = " << tests[i].second << " != " << result << "\n";
			} else {
				std::cout << "Test [" << i + 1 << "] passed\n";
			}
		}
		catch (std::exception& e) {
			std::cerr << "Test [" << i + 1 << "] failed: " << e.what() << "\n";
		}
	}
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
