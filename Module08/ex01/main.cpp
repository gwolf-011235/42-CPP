/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:30:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/18 19:16:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

int		main()
{
	Span	sp(5);
	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(17);

	sp.addNumber(lst.begin(), lst.end());
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print();
	std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
	std::cout << "Longest span: " << sp.longestSpan() << "\n";
	return 0;
}
