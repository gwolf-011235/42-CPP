/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:46:18 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 15:48:03 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// ctor

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("RobotomyRequestForm", 72, 45), m_target(target)
{
	std::cout << "Default constructor called: RobotomyRequestForm \n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) :
	AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	std::cout << "Copy constructor called: RobotomyRequestForm \n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called: RobotomyRequestForm \n";
}

// operators

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	std::cout << "Copy assignment operator called: RobotomyRequestForm \n";
	if (this != &ref) {
		// Cannot copy, type is const
	}
	return (*this);
}

// methods

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << "* drilling noises * \n";
	if (rand() % 2)
		std::cout << m_target << " has been robotomized successfully \n";
	else
		std::cout << m_target << " robotomization failed \n";
}
