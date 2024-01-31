/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:48:26 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/31 11:16:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
// ctor
	PresidentialPardonForm(const std::string& target = "Home");
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	~PresidentialPardonForm();
// operators
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
// methods
	void	execute(const Bureaucrat& executor) const;

private:
// attributes
	const std::string	m_target;
};

#endif
