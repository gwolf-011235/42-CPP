/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:34:23 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/19 10:35:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TEST_HPP
# define ARRAY_TEST_HPP

# include "Array.hpp"

template <typename T>
void	ArrayTest(std::string type, size_t max_val)
{
	std::cout << "*** Testing template class Array ***\n";
	std::cout << "* Type: " << type << " / Elements: " << max_val << "\n\n";
	{
		std::cout << "* Creating Array and mirror\n";

		Array<T>	numbers(max_val);
		T*			mirror = new T[max_val];

		std::cout << "* Filling array and mirror with random numbers\n";
		for (size_t i = 0; i < max_val; ++i) {
			const T value = std::rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		for (size_t i = 0; i < max_val; i++) {
			std::cout << i << ": " << numbers[i] << "\n";
		}
		std::cout << "* Check numbers with mirror\n";
		for (size_t i = 0; i < max_val; i++) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "Didn't save the same value!\n";
				return ;
			}
		}
		std::cout << "* Success: everything is the same\n\n";

		std::cout << "* Testing empty array, copy constructor and copy assignment operator\n";
		{
			std::cout << "* Creating empty Array\n";
			Array<T> tmp;
			std::cout << "* Call Copy constructor on initial Array\n";
			Array<T> test(numbers);
			std::cout << "* Use copy assignment operator on empty Array\n";
			tmp = test;
			std::cout << "* Check if everything is the same\n";
			for (size_t i = 0; i < max_val; i++) {
				if (tmp[i] != numbers[i]) {
					std::cerr << "Didn't save the same value!\n";
					return ;
				}
			}
			std::cout << "* Success: everything is the same\n";
		}
		std::cout << "* Success: empty Array, copy constructor and copy assignment operator work\n\n";

		std::cout << "* Testing out of bounds access\n";
		std::cout << "* Trying to access [-2]:\n";
		try {
			numbers[-2] = 0;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << "* Trying to access [max_val]:\n";
		try {
			numbers[max_val] = 0;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << "* Success: out of bounds detection works\n\n";

		std::cout << "* Fill Array with other values using access operator\n";
		for (size_t i = 0; i < max_val; i++) {
			const T value = std::rand();
			numbers[i] = value;
		}
		for (size_t i = 0; i < max_val; i++) {
			std::cout << i << ": " << numbers[i] << "\n";
		}
		std::cout << "* Success: array can be filled with other values\n\n";

		std::cout << "* Trying access operator on const array\n";
		{
			std::cout << "* Creating const Array\n";
			const Array<T> const_numbers(numbers);
			std::cout << "* Accessing elements\n";
			for (size_t i = 0; i < max_val; i++) {
			std::cout << i << ": " << const_numbers[i] << "\n";
			}
		}
		std::cout << "* Success: const access operator works\n\n";

		delete [] mirror;
	}
	std::cout << "*** End of test ***\n\n";
}

#endif
