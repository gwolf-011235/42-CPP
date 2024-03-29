/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_max.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:18:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 15:31:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_MAX_HPP
# define TEMPLATE_MAX_HPP

template <typename T>
T	max(const T a, const T b)
{
	return (a > b ? a : b);
}

#endif
