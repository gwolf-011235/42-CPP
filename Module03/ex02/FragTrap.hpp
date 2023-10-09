/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:04:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/09 15:13:35 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	/* private stuff */
public:
	FragTrap(const std::string& name = "HappyBoi");
	FragTrap(const FragTrap& ref);
	~FragTrap(void);
	FragTrap& operator= (const FragTrap& ref);

	const std::string	getType() const;

	void	highFivesGuys(void);
};
