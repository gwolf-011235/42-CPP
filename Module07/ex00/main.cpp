/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:19:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/10 13:59:54 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template_swap.hpp"
#include "template_min.hpp"
#include "template_max.hpp"
#include "Data.hpp"
#include <iostream>

void	test_subject(void)
{
	std::cout << "Subject test\n";
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "\n\n";
}

void	test_custom(void)
{
	std::cout << "Custom test\n";
	Data a = {123, "Rice", "White rice", 100};
	Data b = {456, "Beans", "Black beans", 200};

	std::cout << "--- Before swap ---\n";
	std::cout << "Data a\n";
	a.printData();
	std::cout << "Data b\n";
	b.printData();
	::swap(a, b);
	std::cout << "--- After swap--- \n";
	std::cout << "Data a\n";
	a.printData();
	std::cout << "Data b\n";
	b.printData();
	std::cout << "--- Check for min id ---\n";
	std::cout << "min( a, b ) = " << ::min(a, b).id << "\n";
	std::cout << "--- Check for max id ---\n";
	std::cout << "max( a, b ) = " << ::max(a, b).id << "\n";
}

int main( void )
{
	test_subject();
	test_custom();
	return 0;
}
