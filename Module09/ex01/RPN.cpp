/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:51 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/04 15:53:49 by gwolf            ###   ########.fr       */
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

int	RPN::evaluate(const std::string input)
{
	if (input.empty())
		throw std::runtime_error(ERR_EMPTY_INPUT);
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
			int num = m_stack.top();
			m_stack.pop();
			switch (*it)
			{
				case '+':
					m_stack.top() += num;
					break;
				case '-':
					m_stack.top() -= num;
					break;
				case '*':
					m_stack.top() *= num;
					break;
				case '/':
					if (num == 0)
						throw std::runtime_error(ERR_DIV_BY_ZERO);
					m_stack.top() /= num;
					break;
			}
			if (m_stack.top() > std::numeric_limits<int>::max() || m_stack.top() < std::numeric_limits<int>::min())
				throw std::runtime_error(ERR_OVERFLOW);
		}
	}
	if (m_stack.size() != 1)
		throw std::runtime_error(ERR_NOT_ENOUGH_OP);
	int result = m_stack.top();
	m_stack.pop();
	return (result);
}

