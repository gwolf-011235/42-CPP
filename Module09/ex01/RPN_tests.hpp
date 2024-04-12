/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:10:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/12 15:12:06 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_TESTS_HPP
# define RPN_TESTS_HPP

# include <iostream>
# include "RPN.hpp"

void	test_loop(std::string testname, std::pair<std::string, double> tests[], size_t size);
void	test_correct(void);
void	test_invalid(void);
void	test_not_in_scope(void);

#endif
