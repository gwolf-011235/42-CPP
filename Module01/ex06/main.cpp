/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/19 01:51:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string check_arg(char* argv)
{
	int i;
	for (i = 0; i < 7 && argv[i]; ++i) {
		argv[i] = std::toupper(argv[i]);
	}
	if (i == 7 && argv[i]) {
		return "";
	}
	std::string input(argv);
	return input;
}

void	print_error(const char* prog)
{
	std::cerr << "Input not recognized!\n";
	std::cerr << "Please provide one of the following levels:\n";
	std::cerr << "debug, warning, info, error\n";
	print_usage(prog);
}

void	print_usage(const char* prog)
{
	std::cout << "usage: " << prog << " str_level\n";
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		print_usage(argv[0]);
		return 1;
	}
	std::string input = check_arg(argv[1]);
	if (input.empty()) {
		print_error(argv[0]);
		return 1;
	}
	switch (input.at(0))
	{
	case 'D':
		if (input != "DEBUG") {
			print_error(argv[0]);
			return 1;
		}
		Harl::set_level(level_debug);
		break;

	default:
		break;
	}
	Harl harl;
	std::string level[5] = {"debug", "warning", "info", "error", "noexist"};

	for (int i = 0; i < 5; ++i) {
		std::cout << "Complain level " << level[i] << ": \n";
		harl.complain(level[i]);
		std::cout << '\n';
	}
}