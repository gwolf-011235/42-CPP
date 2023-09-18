/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/18 21:34:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "Complain level debug: \n";
	harl.complain("debug");
	std::cout << "Complain level warning: \n";
	harl.complain("warning");
	std::cout << "Complain level info: \n";
	harl.complain("info");
	std::cout << "Complain level error: \n";
	harl.complain("error");
	std::cout << "Complain level noexist: \n";
	harl.complain("noexist");
}