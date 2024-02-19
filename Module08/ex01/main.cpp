/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:30:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/19 11:07:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <ctime>

void	test_too_many(void)
{
	std::cout << "** Test too many numbers\n";
	std::cout << "Creating Span with size 5 and add 6 numbers\n";

	Span	span(5);

	try {
		for (unsigned int i = 0; i < 6; ++i) {
			span.addNumber(i);
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	span.print();
	std::cout << "** End of test\n\n";
}

void	test_not_enough(void)
{
	std::cout << "** Test not enough numbers\n";
	std::cout << "Creating an empty Span with size 5 and try to get the shortest / longest span\n";

	Span	span(5);

	try {
		std::cout << "Shortest span: " << span.shortestSpan() << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << "Longest span: " << span.longestSpan() << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "Add one element to span and try again\n";
	span.addNumber(5);
	try {
		std::cout << "Shortest span: " << span.shortestSpan() << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << "Longest span: " << span.longestSpan() << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "** End of test\n\n";
}

void	test_add_range(void)
{
	std::cout << "** Test add range\n";
	std::cout << "Creating Span with size 5 and add 3 numbers from a list\n";

	Span	span(5);
	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(17);

	span.addNumber(lst.begin(), lst.end());
	span.print();
	std::cout << "** End of test\n\n";
}

void	test_range_too_big(void)
{
	std::cout << "** Test range too big\n";
	std::cout << "Creating Span with size 5 and add 6 numbers from a list\n";

	Span	span(5);
	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(9);
	lst.push_back(11);
	lst.push_back(13);

	try {
		span.addNumber(lst.begin(), lst.end());
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	span.print();
	std::cout << "** End of test\n\n";
}

void	test_spans_with_random(unsigned int count, unsigned int range, bool print = true)
{
	std::cout << "** Test spans with random numbers\n";
	std::cout << "Creating Span with size " << count << " and add random numbers in range " << range << "\n";

	Span	span(count);
	for (unsigned int i = 0; i < count; ++i) {
		span.addNumber(std::rand() % range);
	}
	if (print)
		span.print();
	std::cout << "Shortest span: " << span.shortestSpan() << "\n";
	std::cout << "Longest span: " << span.longestSpan() << "\n";
	std::cout << "** End of test\n\n";
}

int		main()
{
	test_too_many();
	test_not_enough();

	test_add_range();
	test_range_too_big();

	std::srand(std::time(0));
	test_spans_with_random(5, 100);
	test_spans_with_random(10000, 100000, false);
	
	return 0;
}
