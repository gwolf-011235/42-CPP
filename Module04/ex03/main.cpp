/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:33:53 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 13:59:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	testOverfill(void)
{
	IMateriaSource* src = new MateriaSource();
	for (int i = 0; i != 5; ++i) {
		src->learnMateria(new Ice());
	}

	Floor floor;
	ICharacter* me = new Character("gwolf", &floor);
	for (int i = 0; i != 5; ++i) {
		me->equip(new Cure());
	}
	delete me;
	delete src;

}

void	testFromSubject(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int	main(void)
{
	//testFromSubject();
	testOverfill();
	return 0;
}