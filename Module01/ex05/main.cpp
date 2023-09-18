/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:42 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/18 21:53:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::string level[5] = {"debug", "warning", "info", "error", "noexist"};

	for (int i = 0; i < 5; ++i) {
		std::cout << "Complain level " << level[i] << ": \n";
		harl.complain(level[i]);
		std::cout << '\n';
	}
}