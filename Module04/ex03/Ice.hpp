/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:30:27 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 21:30:55 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Ice
{
public:
	Ice(void);
	Ice(const Ice& ref);
	~Ice(void);
	Ice& operator= (const Ice& ref);
private:
	/* private stuff */
};
