/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:57:23 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/21 14:38:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	test_from_subject(void)
{
	std::cout << "* Test from subject\n";
	MutantStack<int>
	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "* End of test\n";
}

void	test_const_iterator(void)
{
	std::cout << "* Test const_iterator\n";
	MutantStack<double> mstack;
	mstack.push(6.1);
	mstack.push(18.2);
	mstack.push(4.3);
	mstack.push(7.4);
	mstack.push(783.5);
	mstack.push(0.6);
	MutantStack<double>::const_iterator it = mstack.cbegin();
	MutantStack<double>::const_iterator ite = mstack.cend();
	while (it != ite)
	{
		std::cout << *it << " - ";
		++it;
	}
	std::cout << "END\n";
	std::cout << "* End of test\n";
}

void	test_use_iterator(void)
{
	std::cout << "* Test use iterator\n";
	MutantStack<unsigned int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(0);
	MutantStack<unsigned int>::iterator it = mstack.begin();
	MutantStack<unsigned int>::iterator ite = mstack.end();
	std::cout << "Elements of stack: \n";
	while (it != ite)
	{
		std::cout << *it << " - ";
		++it;
	}
	std::cout << "END\n";
	it = mstack.begin();
	std::cout << "Add 1 to each element of stack.\n";
	while (it != ite)
	{
		*it += 1;
		++it;
	}
	it = mstack.begin();
	std::cout << "Elements after manipulation: \n";
	while (it != ite)
	{
		std::cout << *it << " - ";
		++it;
	}
	std::cout << "END\n";
	std::cout << "* End of test\n";
}

int main()
{
	test_from_subject();
	test_const_iterator();
	test_use_iterator();
	return 0;
}
