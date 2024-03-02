/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:51 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/02 14:39:59 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN& ref)
{
	*this = ref;
}

RPN& RPN::operator=(const RPN& ref)
{
	if (this == &ref)
		return *this;
	m_stack = ref.m_stack;
	return *this;
}

RPN::~RPN(void)
{
}

void	RPN::evaluate(const std::string input)
{
	if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::invalid_argument("Invalid input: Only numbers and + - * / are allowed");

	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (*it == ' ')
			continue;

		if (*(it + 1) != ' ' && *(it + 1) != '\0')
			throw std::invalid_argument("Invalid input: Numbers below 10");

		if (std::isdigit(*it))
		{
			m_stack.push(*it - '0');
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (m_stack.size() < 2)
				throw std::invalid_argument("Invalid input");
			double a = m_stack.top();
			m_stack.pop();
			double b = m_stack.top();
			m_stack.pop();
			switch (*it)
			{
				case '+':
					m_stack.push(a + b);
					break;
				case '-':
					m_stack.push(a - b);
					break;
				case '*':
					m_stack.push(a * b);
					break;
				case '/':
					m_stack.push(a / b);
					break;
			}
		}
	}
	if (m_stack.size() != 1)
		throw std::invalid_argument("Invalid input");
	std::cout << m_stack.top() << "\n";
}
