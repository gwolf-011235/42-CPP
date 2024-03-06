/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:25:19 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/06 10:52:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, const int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, const int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return it;
}

template <typename T>
void test_easyfind(const T& container, const int value)
{
	std::cout << "Testing easyfind with value: " << value << "\n";
	try {
		typename T::const_iterator it = easyfind(container, value);
		std::cout << "Found: " << *it << "\n";
	} catch (std::exception &e) {
		std::cerr << "Not found: " << value << "\n";
	}
}

#endif
