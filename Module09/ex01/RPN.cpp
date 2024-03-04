/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:51 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/04 10:03:18 by gwolf            ###   ########.fr       */
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
		throw std::runtime_error(ERR_INVALID_CHARS);

	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (*it == ' ')
			continue;
		else if (std::isdigit(*it))
		{
			if (*(it + 1) != ' ' && *(it + 1) != '\0')
				throw std::runtime_error(ERR_INVALID_NUM);
			m_stack.push(*it - '0');
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (m_stack.size() < 2)
				throw std::runtime_error(ERR_NOT_ENOUGH_NUM);
			if (*(it + 1) != ' ' && *(it + 1) != '\0')
				throw std::runtime_error(ERR_INVALID_OP);
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
		throw std::runtime_error(ERR_NOT_ENOUGH_OP);
}

double	RPN::getResult(void)
{
	if (m_stack.size() != 1)
		throw std::invalid_argument(ERR_STACK_SIZE);

	double result = m_stack.top();
	m_stack.pop();
	return (result);
}
