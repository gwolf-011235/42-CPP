/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:27:26 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/19 02:08:29 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) : m_map(construct_map())
{
}

Harl::~Harl( void )
{
}

void	Harl::debug( void )
{
	if (m_level > level_debug) {
		return;
	}
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	if (m_level > level_info) {
		return;
	}
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	if (m_level > level_warning) {
		return;
	}
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	memfunptr p;
	try {
		p = m_map.at(level);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of range error: " << oor.what() << '\n';
		std::cerr << "Complain level '" << level << "' not recognized" << '\n';
		return ;
	}
	return (this->*p)();
}

Harl::memfunptr_map	Harl::construct_map( void )
{
	memfunptr_map map;
	map["debug"] = &Harl::debug;
	map["info"] = &Harl::info;
	map["warning"] = &Harl::warning;
	map["error"] = &Harl::error;
	return map;
}

void	Harl::set_level(Harl::e_level level)
{
	m_level = level;
}