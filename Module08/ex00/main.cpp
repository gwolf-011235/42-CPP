/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:27:14 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 18:12:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>

#include "easyfind.hpp"

int main(void)
{
	static const int arr[] = {1, 2, 3, 4, 5};
	std::cout << "*** Testing with vector ***\n";
	{
		std::vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
		test_easyfind(vec, 3);
		test_easyfind(vec, 6);
		vec.push_back(6);
		test_easyfind(vec, 6);
		std::cout << "Testing with const vector\n";
		const std::vector<int> cvec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
		test_easyfind(cvec, 3);
		test_easyfind(cvec, 6);
		std::cout << "Testing with empty vector\n";
		std::vector<int> empty;
		test_easyfind(empty, 3);
		std::cout << "*** Finished ***\n\n";
	}
	std::cout << "*** Testing with list ***\n";
	{
		std::list<int> lst (arr, arr + sizeof(arr) / sizeof(arr[0]) );
		test_easyfind(lst, 3);
		test_easyfind(lst, 6);
		lst.push_back(6);
		test_easyfind(lst, 6);
		std::cout << "*** Finished ***\n\n";
	}
	std::cout << "*** Testing with set ***\n";
	{
		std::set<int> set (arr, arr + sizeof(arr) / sizeof(arr[0]) );
		test_easyfind(set, 3);
		test_easyfind(set, 6);
		set.insert(6);
		test_easyfind(set, 6);
		std::cout << "*** Finished ***\n\n";
	}
	return 0;
}
