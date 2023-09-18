/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/18 21:44:32 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <map>

//typedef void (Harl::*harl_mem_funptr)( void );
//typedef std::map<std::string, harl_mem_funptr> funptr_map;

class Harl
{
typedef void (Harl::*memfunptr)(void);
typedef std::map<std::string, memfunptr> memfunptr_map;

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	memfunptr_map construct_map( void );
	const memfunptr_map map;
public:
	Harl( void );
	~Harl( void );
	void complain(std::string level);
};


#endif