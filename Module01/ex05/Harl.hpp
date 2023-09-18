/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/19 01:56:04 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <map>

class Harl
{
typedef void (Harl::*memfunptr)(void);
typedef std::map<std::string, memfunptr> memfunptr_map;

private:
	const memfunptr_map m_map;

	memfunptr_map construct_map( void );
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	Harl( void );
	~Harl( void );

	void complain(std::string level);
};

#endif