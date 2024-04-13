/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 11:13:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <algorithm>

# include "ford_johnson.hpp"
# include "utils.hpp"

class PmergeMe
{
public:
	PmergeMe(int argc, char** argv);
	~PmergeMe(void);

	double	time_for_vector(void) const;
	double	time_for_list(void) const;
private:
	PmergeMe(void);
	PmergeMe(const PmergeMe& ref);
	PmergeMe& operator= (const PmergeMe& ref);

	const int	m_argc;
	char**		m_argv;
};

#endif
