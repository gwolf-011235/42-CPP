/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:45:14 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 15:55:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
public:
// ctor
	RobotomyRequestForm(const std::string& target = "Home");
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();
// operators
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
// methods
	void	execute(const Bureaucrat& executor) const;

private:
	const std::string	m_target;
};

#endif
