/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/04 10:03:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <stdexcept>

# define ERR_INVALID_CHARS "Invalid input: Only numbers 0 to 9 and operators + - * / are allowed"
# define ERR_INVALID_NUM "Invalid number: Only single digit numbers, no signs are allowed"
# define ERR_NOT_ENOUGH_NUM "Not enough numbers to compute"
# define ERR_INVALID_OP "Invalid operator: Only + - / * separated by space"
# define ERR_NOT_ENOUGH_OP "Not enough operators to compute"
# define ERR_STACK_SIZE "No computed value on stack"

class RPN
{
public:
	RPN(void);
	RPN(const RPN& ref);
	~RPN(void);
	RPN& operator= (const RPN& ref);

	void	evaluate(const std::string input);
	double	getResult(void);

private:
	std::stack<double>	m_stack;
};

#endif
