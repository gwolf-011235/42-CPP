/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_max.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:18:53 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/07 17:19:07 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_MAX_HPP
# define TEMPLATE_MAX_HPP

template <typename T>
T	max(T a, T b)
{
	return (a > b ? a : b);
}

#endif
