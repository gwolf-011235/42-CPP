/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:10:38 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/12 15:11:52 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN_tests.hpp"

void	test_loop(std::string testname, std::pair<std::string, double> tests[], size_t size)
{
	std::cout << "TEST " << testname << "\n";
	RPN	rpn;

	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Test [" << i + 1 << "]: '" << tests[i].first << "' = " << tests[i].second << "\n";
		try {
			double result = rpn.evaluate(tests[i].first);
			if (result != tests[i].second) {
				std::cerr << "Failed! Expected: " << tests[i].second << " but got: " << result << "\n";
			} else {
				std::cout << "Passed!\n";
			}
		}
		catch (std::exception& e) {
			std::cerr << "Exception: " << e.what() << "\n";
		}
	}
	std::cout << "END\n\n";
}

void	test_correct(void)
{
	std::pair<std::string, double> tests[] = {
		std::make_pair("1 2 +", 3),
		std::make_pair("5 3 -", 2),
		std::make_pair("9 4 *", 36),
		std::make_pair("7 8 /", 0),
		std::make_pair("5 3 + 2 *", 16),
		std::make_pair("3 4 * 5 6 * +", 42),
		std::make_pair("5 2 2 * * 9 + 7 6 * -", -13),
		std::make_pair("      2      5     +   ", 7)
	};

	test_loop("Correct input", tests, sizeof(tests) / sizeof(tests[0]));
}

void	test_invalid(void)
{
	std::pair<std::string, double> tests[] = {
		std::make_pair("1 2 H", -1),
		std::make_pair("12 3 +", -1),
		std::make_pair("9 /", -1),
		std::make_pair("2 2 2 **", -1),
		std::make_pair("1 2 3 +", -1),
		std::make_pair("9 9 9 9 9 9 9 9 9 9 9 * * * * * * * * * *", -1),
		std::make_pair("4 4 4 - /", -1),
		std::make_pair("", -1)
	};

	test_loop("Invalid input", tests, sizeof(tests) / sizeof(tests[0]));
}

void	test_not_in_scope(void)
{
	std::pair<std::string, double> tests[] = {
		std::make_pair("(1 2) + (2 4) + +", -1),
		std::make_pair("5 2 /", 5.0 / 2.0),
	};

	test_loop("Not in scope", tests, sizeof(tests) / sizeof(tests[0]));
}