/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/19 02:05:48 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <map>

class Harl
{
private:
typedef void (Harl::*memfunptr)(void);
typedef std::map<std::string, memfunptr> memfunptr_map;

public:
typedef enum level {level_debug, level_info, level_warning, level_error} e_level;

private:
	const memfunptr_map m_map;
	e_level m_level;

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	memfunptr_map construct_map( void );

public:
	Harl( void );
	~Harl( void );

	void	complain(std::string level);
	void	set_level(e_level level);
};

#endif