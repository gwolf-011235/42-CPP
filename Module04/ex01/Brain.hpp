/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:13:54 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 09:33:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Brain
{
public:
	Brain(void);
	Brain(const Brain& ref);
	~Brain(void);
	Brain& operator= (const Brain& ref);
	void	setIdea(const std::string& idea, int index);
	void	printIdea(int index) const;
	void	printEverything() const;
private:
	std::string ideas[100];
};
