/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:33:53 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/18 19:26:26by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	testCharacter(void)
{
	ICharacter* me;

	std::cout << "TEST Character Default\n";
	me = new Character();
	me->equip(new Ice());
	delete me;
	std::cout << "FINISH\n\n";

	std::cout << "TEST Character Param\n";
	me = new Character("Finn");
	me->equip(new Cure());
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());
	me->unequip(0);
	me->unequip(2);
	std::cout << "FINISH\n\n";

	std::cout << "TEST Character Copy and Assignment\n";
	Character you(*dynamic_cast<Character*>(me));
	you.printInventory();

	Character dog("Jake");
	dog = you;
	dog.unequip(1);
}

void	testOverfill(void)
{
	std::cout << "TEST Overfill MateriaSource\n";
	IMateriaSource* src = new MateriaSource();
	for (int i = 0; i != 5; ++i) {
		src->learnMateria(new Ice());
	}
	delete src;
	std::cout << "FINISH\n\n";

	std::cout << "TEST Overfill Character\n";
	ICharacter* me = new Character("Fiona");
	for (int i = 0; i != 5; ++i) {
		me->equip(new Cure());
	}
	delete me;
	std::cout << "FINISH\n\n";

	std::cout << "TEST Overfill Floor\n";
	me = new Character("Cake");
	for (int i = 0; i != 14; i+=2) {
		me->equip(new Ice());
		me->equip(new Cure());
	}
	delete me;
	std::cout << "FINISH\n\n";
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
	std::cout << "STARTING TESTS\n\n";
	//testFromSubject();
	testCharacter();
	//testOverfill();
	return 0;
}