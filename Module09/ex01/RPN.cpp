/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:51 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/03 09:01:29 by gwolf            ###   ########.fr       */
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
		else if (std::isdigit(*it))
		{
			if (*(it + 1) != ' ' && *(it + 1) != '\0')
				throw std::invalid_argument("Invalid input: Only numbers below 10");
			m_stack.push(*it - '0');
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (m_stack.size() < 2)
				throw std::invalid_argument("Invalid input: Not enough numbers to compute");
			if (*(it + 1) != ' ' && *(it + 1) != '\0')
				throw std::invalid_argument("Invalid input: Only operators: + - / *");
			double b = m_stack.top();
			m_stack.pop();
			double a = m_stack.top();
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
		throw std::invalid_argument("Invalid input: Not enough operators to compute");
}

double	RPN::getResult(void)
{
	if (m_stack.size() != 1)
		throw std::invalid_argument("Invalid input: No computed value on stack");

	double result = m_stack.top();
	m_stack.pop();
	return (result);
}
