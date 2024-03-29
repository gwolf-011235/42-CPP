/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:44:13 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/12 15:50:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

struct Data
{
	Data& operator= (const Data& ref);
	bool operator< (const Data& ref) const;
	bool operator> (const Data& ref) const;

	int 		id;
	std::string name;
	std::string	description;
	int 		count;
};

std::ostream& operator<< (std::ostream& os, const Data& ref);

#endif
