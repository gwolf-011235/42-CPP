/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/06 11:30:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <stdexcept>
# include <limits>

# define ERR_INVALID_CHARS "Invalid input: Only numbers 0 to 9 and operators + - * / are allowed"
# define ERR_INVALID_NUM "Invalid number: Only single digit numbers, no signs are allowed"
# define ERR_NOT_ENOUGH_NUM "Not enough numbers to compute"
# define ERR_INVALID_OP "Invalid operator: Only + - / * separated by space"
# define ERR_NOT_ENOUGH_OP "Not enough operators to compute"
# define ERR_STACK_SIZE "No computed value on stack"
# define ERR_DIV_BY_ZERO "Division by zero not possible"
# define ERR_OVERFLOW "Overflow: Result is too big to be stored"
# define ERR_EMPTY_INPUT "Invalid input: Empty string"

class RPN
{
public:
	RPN(void);
	RPN(const RPN& ref);
	~RPN(void);
	RPN& operator= (const RPN& ref);

	int	evaluate(const std::string input);

private:
	std::stack<long>	m_stack;
};

#endif
