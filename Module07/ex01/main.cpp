/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:19:51 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 16:21:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "iter_test.hpp"

# define ARR_SIZE 5



int		main()
{
	int			intArray[ARR_SIZE] = {1, 2, 3, 4, 5};
	float		floatArray[ARR_SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double		doubleArray[ARR_SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string	stringArray[ARR_SIZE] = {"one", "two", "three", "four", "five"};
	Data		DataArray[ARR_SIZE] = {
		{123, "Rice", "White rice", 100},
		{456, "Beans", "Black beans", 200},
		{789, "Pasta", "Spaghetti", 300},
		{101, "Potato", "Sweet potato", 400},
		{112, "Tomato", "Cherry tomato", 500}
	};

	test_iter("int", intArray, 5);
	test_iter("float", floatArray, 5);
	test_iter("double", doubleArray, 5);
	test_iter("string", stringArray, 5);
	test_iter("Data", DataArray, 5);

	return 0;
}
