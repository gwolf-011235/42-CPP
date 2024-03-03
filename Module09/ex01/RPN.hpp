/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:30 by gwolf             #+#    #+#             */
/*   Updated: 2024/03/03 08:34:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <stdexcept>

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
