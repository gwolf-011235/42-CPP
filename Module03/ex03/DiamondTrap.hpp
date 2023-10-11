/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:56:28 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/11 15:51:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	m_name;
public:
	DiamondTrap(const std::string& name = "ShinyBoii");
	DiamondTrap(const DiamondTrap& ref);
	~DiamondTrap(void);
	DiamondTrap& operator= (const DiamondTrap& ref);

	const std::string&	getName() const;
	const std::string	getType() const;

	void	printStats() const;
	void	attack(const std::string& target);
	void	whoAmI();
};
