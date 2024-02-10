/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:44:13 by gwolf             #+#    #+#             */
/*   Updated: 2024/02/10 13:30:22 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>

struct Data
{
	Data(int id = 0, std::string name = "", std::string description = "", int count = 0);
	Data(const Data& ref);
	~Data();
	Data& operator= (const Data& ref);
	bool operator< (const Data& ref) const;
	bool operator> (const Data& ref) const;
	void	printData(void);
	int 		id;
	std::string name;
	std::string	description;
	int 		count;
};

#endif
