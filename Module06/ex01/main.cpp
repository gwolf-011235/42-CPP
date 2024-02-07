/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:04:31 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/07 17:00:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int		main(void)
{
	Data		data(42, "g_sugar", "The best sweetener in town", 3);
	uintptr_t	serialized;
	Data*		deserialized;

	std::cout << "Address of data: " << &data << "\n";
	serialized = Serializer::serialize(&data);
	std::cout << "Serialized: " << serialized << "\n";
	deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized << "\n";

	data.printData();


	return (0);
}
