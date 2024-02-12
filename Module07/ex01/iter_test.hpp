/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_test.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:20:13 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 16:23:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_TEST_HPP
# define ITER_TEST_HPP

# include <iostream>
# include <string>
# include "iter.hpp"
# include "Data.hpp"
# include "print.hpp"

void	increment(int &x);
void	increment(float &x);
void	increment(double &x);
void	increment(std::string &x);
void	increment(Data &x);

template< typename T >
void	test_iter(const std::string type, T &x, const size_t size)
{
	std::cout << "*** Testing iter with " << type << "Array ***\n\n";
	std::cout << "* Print " << type << "Array\n";
	iter(x, size, print);
	std::cout << "* Incrementing\n";
	iter(x, size, increment);
	std::cout << "* Print new " << type << "Array:\n";
	iter(x, size, print);
	std::cout << "*** Finished ***\n\n";
}

#endif
