/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:56:35 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/12 15:27:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN_tests.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"<expression>\"" << std::endl;
		return 1;
	}

	if (std::string(argv[1]) == "test")
	{
		test_correct();
		test_invalid();
		test_not_in_scope();
		return 0;
	}

	RPN	rpn;

	try {
		std::cout << rpn.evaluate(argv[1]) << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "ERROR: " << e.what() << "\n";
		return 1;
	}
	return 0;
}
