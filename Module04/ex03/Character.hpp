/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:32:21 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 21:32:33 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Character
{
public:
	Character(void);
	Character(const Character& ref);
	~Character(void);
	Character& operator= (const Character& ref);
private:
	/* private stuff */
};
