/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_johnson.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:58:59 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/13 11:14:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORD_JOHNSON_HPP
# define FORD_JOHNSON_HPP

# include <vector>
# include <list>

# include "GroupIterator.hpp"

// Typedef of a std::pair for pend elements in vector implemenation
typedef std::pair<GroupIterator, std::list<GroupIterator>::iterator> vec_node;

// Small node struct for pend elements in list implemenation
typedef struct list_node
{
	std::list<std::list<unsigned int>::iterator>::iterator pair_head;
	std::list<unsigned int>::iterator begin;
	std::list<unsigned int>::iterator end;
}	list_node;

std::size_t	calc_jacobsthal_num(std::size_t n);
std::size_t	calc_diff_jacobsthal_num(std::size_t n);

std::size_t	ford_johnson_vec(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
std::size_t	ford_johnson_list(std::list<unsigned int>& list);

#endif
