/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:24:50 by gwolf             #+#    #+#             */
/*   Updated: 2023/09/17 20:05:59 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <map>

class Harl
{
typedef void(Harl::*HarlMemFunptr)(void);
typedef std::map<std::string, HarlMemFunptr> funptrMap;

private:
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