/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:12:29 by gwolf             #+#    #+#             */
/*   Updated: 2024/04/10 14:45:30 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <stdexcept>
#include <iostream>
#include <sys/time.h>

namespace utils {

	template <typename T>
	void	print_container(const T &t)
	{
		for (typename T::const_iterator it = t.begin(); it != t.end(); ++it) {
			std::cout << *it << ' ';
		}
		std::cout << '\n';
	}

	void		check_args(const int argc, char** argv);
	std::size_t	ft_jacobsthal(std::size_t n);
	std::size_t	ft_calc_jacobsthal_diff(std::size_t n);
}

#endif
