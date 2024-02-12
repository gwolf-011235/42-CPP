/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_min.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:17:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 15:32:33 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_MIN_HPP
# define TEMPLATE_MIN_HPP

template <typename T>
T	min(const T a, const T b)
{
	return (a < b ? a : b);
}

#endif
