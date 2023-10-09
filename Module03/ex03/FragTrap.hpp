/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:04:08 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/09 16:07:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
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
