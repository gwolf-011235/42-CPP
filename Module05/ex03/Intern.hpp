/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:48:23 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 11:23:50 by gwolf            ###   ########.fr       */
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
// typedefs
	typedef AForm* (Intern::*FormCreationFunc)(const std::string&) const;
// methods
	AForm*	createShrubberyCreationForm(const std::string& target) const;
	AForm*	createRobotomyRequestForm(const std::string& target) const;
	AForm*	createPresidentialPardonForm(const std::string& target) const;
// attributes
	static const int	m_knownForms = 3;
};

#endif
