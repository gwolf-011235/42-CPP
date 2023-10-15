/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:31:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/15 21:31:40 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Cure
{
public:
	Cure(void);
	Cure(const Cure& ref);
	~Cure(void);
	Cure& operator= (const Cure& ref);
private:
	/* private stuff */
};
