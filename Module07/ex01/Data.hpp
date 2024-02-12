/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:44:13 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/10 13:52:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

struct Data
{
	int 		id;
	std::string name;
	std::string	description;
	int 		count;
};

std::ostream& operator<< (std::ostream& os, const Data& ref);

#endif
