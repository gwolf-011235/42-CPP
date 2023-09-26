/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/26 14:40:59 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string check_arg(char* argv)
{
	int i;
	for (i = 0; i < 7 && argv[i]; ++i) {
		argv[i] = std::toupper(argv[i]);
	}
	if (i < 4 || (i == 7 && argv[i])) {
		return "";
	}
	std::string input(argv);
	return input;
}

void	print_usage(const char* prog)
{
	std::cout << "usage: " << prog << " str_level\n";
}

void	print_normal()
{
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		print_usage(argv[0]);
		return 1;
	}

	std::string input = check_arg(argv[1]);
	if (input.empty()) {
		print_normal();
		return 1;
	}

	Harl harl;
	switch (input.at(0))
	{
	case 'D':
		if (input != "DEBUG") {
			print_normal();
			return 1;
		}
		harl.set_level(Harl::level_debug);
		break;

	case 'I':
		if (input != "INFO") {
			print_normal();
			return 1;
		}
		harl.set_level(Harl::level_info);
		break;

	case 'W':
		if (input != "WARNING") {
			print_normal();
			return 1;
		}
		harl.set_level(Harl::level_warning);
		break;

	case 'E':
		if (input != "ERROR") {
			print_normal();
			return 1;
		}
		harl.set_level(Harl::level_error);
		break;

	default:
		print_normal();
		return 1;
	}

	std::string level[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; ++i) {
		harl.complain(level[i]);
	}
}