/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:44:06 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 13:27:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
	Zombie 		*ptr;
	int			count = 5;
	std::string name = "guys";

	ptr = zombieHorde(count, name);
	for (int i = 0; i < count; i++) {
		std::cout << "Zombie #" << i + 1 << std::endl;
		ptr[i].announce();
	};
	delete[] ptr;
	return 0;
}
