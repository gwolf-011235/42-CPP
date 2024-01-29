/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:49:20 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 15:50:00 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// ctor

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("PresidentialPardonForm", 25, 5), m_target(target)
{
	std::cout << "Default constructor called: PresidentialPardonForm \n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) :
	AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	std::cout << "Copy constructor called: PresidentialPardonForm \n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called: PresidentialPardonForm \n";
}

// operators

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	std::cout << "Copy assignment operator called: PresidentialPardonForm \n";
	if (this != &ref) {
		// Cannot copy, type is const
	}
	return (*this);
}

// methods

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << m_target << " has been pardoned by Zafod Beeblebrox \n";
}
