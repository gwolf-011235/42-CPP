/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:57:56 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 13:13:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombie_array = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombie_array[i] = Zombie(name);
	};
	return zombie_array;
}