/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:08:31 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/07 14:12:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int id, std::string name, std::string description, int count) :
	id(id), name(name), description(description), count(count)
{
	return ;
}

void	Data::printData(void)
{
	std::cout << "id:\t\t" << id << "\n";
	std::cout << "name:\t\t" << name << "\n";
	std::cout << "description:\t" << description << "\n";
	std::cout << "count:\t\t" << count << "\n";
}
