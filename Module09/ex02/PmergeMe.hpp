/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:04:36 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/09 17:47:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <string>
# include <iostream>
# include <utility>
# include <algorithm>

class PmergeMe
{
public:
	PmergeMe(const int argc, const char **argv);
	~PmergeMe(void);
private:
	PmergeMe(void);
	PmergeMe(const PmergeMe& ref);
	PmergeMe& operator= (const PmergeMe& ref);

	std::vector<unsigned int>	m_vec;
	std::list<unsigned int>		m_list;
	const int					m_argc;
	std::vector<std::string>	m_argv_as_string;
};


void	print_vector(std::string str, std::vector<int>::iterator begin, std::vector<int>::iterator end);
void	print_list(std::string str, std::list<int>::iterator begin, std::list<int>::iterator end);
size_t	ft_jacobsthal(size_t n);
size_t	ft_calc_jacobsthal_diff(size_t n);

std::size_t	ford_johnson_vec(std::vector<int>::iterator begin, std::vector<int>::iterator end);
std::size_t	ford_johnson_list(std::list<int>& list);

#endif
