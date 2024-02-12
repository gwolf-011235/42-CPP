/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:08:31 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/10 13:53:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

std::ostream& operator<< (std::ostream& os, const Data& ref)
{
	os << "id:\t\t" << ref.id << "\n";
	os << "name:\t\t" << ref.name << "\n";
	os << "description:\t" << ref.description << "\n";
	os << "count:\t\t" << ref.count << "\n";
	return os;
}
