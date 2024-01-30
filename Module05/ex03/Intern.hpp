/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:48:23 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 00:53:22 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
// ctor
	Intern(void);
	Intern(const Intern& ref);
	~Intern(void);
// operators
	Intern& operator= (const Intern& ref);
// methods
	AForm*	makeForm(const std::string& formName, const std::string& target) const;
private:
	typedef AForm* (Intern::*FormCreationFunc)(const std::string&) const;

	AForm*			createShrubberyCreationForm(const std::string& target) const;
	AForm*			createRobotomyRequestForm(const std::string& target) const;
	AForm*			createPresidentialPardonForm(const std::string& target) const;
};

#endif
