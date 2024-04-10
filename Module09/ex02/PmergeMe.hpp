/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/10 14:47:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <algorithm>

# include "utils.hpp"

class PmergeMe
{
public:
	PmergeMe(int argc, char** argv);
	~PmergeMe(void);

	void	time_for_vector(void);
	void	time_for_list(void);
private:
	PmergeMe(void);
	PmergeMe(const PmergeMe& ref);
	PmergeMe& operator= (const PmergeMe& ref);

	const int	m_argc;
	char**		m_argv;
};


std::size_t	ford_johnson_vec(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
std::size_t	ford_johnson_list(std::list<unsigned int>& list);

#endif
