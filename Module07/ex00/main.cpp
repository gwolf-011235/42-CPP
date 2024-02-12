/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:19:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 15:58:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template_swap.hpp"
#include "template_min.hpp"
#include "template_max.hpp"
#include "Data.hpp"
#include <iostream>

void	test_subject(void)
{
	std::cout << "*** Subject test (enhanced) ***\n\n";

	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "* Showcasing swap, min and max *\n";
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "\n";

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "* Showcasing swap, min and max *\n";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "\n";

	std::cout << "*** End of subject test ***\n\n";
}

void	test_custom(void)
{
	std::cout << "*** Custom test ***\n\n";

	Data a = {123, "Rice", "White rice", 100};
	Data b = {456, "Beans", "Black beans", 200};
	std::cout << "Data a\n" << a << "Data b\n" << b;
	std::cout << "* Showcasing swap, min and max *\n";
	::swap(a, b);
	std::cout << "Data a\n" << a << "Data b\n" << b;
	std::cout << "min( a, b ) = " << ::min(a, b).id << "\n";
	std::cout << "max( a, b ) = " << ::max(a, b).id << "\n";
	std::cout << "\n";

	std::cout << "*** End of custom test ***\n\n";
}

int main( void )
{
	test_subject();
	test_custom();
	return 0;
}
