/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:17:49 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/29 15:39:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
// ctor
	ShrubberyCreationForm(const std::string& target = "Home");
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	~ShrubberyCreationForm();
// operators
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
// methods
	void	execute(const Bureaucrat& executor) const;

private:
	const std::string	m_target;
};

#endif
