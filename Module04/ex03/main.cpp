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

void	testMateriaSourceMethods(void)
{
	std::cout << "TEST MateriaSource Methods\n";
	Character me("Bubblegum");
	MateriaSource src("Candy Kingdom");
	AMateria* array[6];
	for (int i = 0; i != 6; i += 2) {
		array[i] = new Ice();
		array[i + 1] = new Cure();
	}

	for (int i = 0; i != 6; ++i) {
		src.learnMateria(array[i]);
	}
	me.equip(src.createMateria("ice"));
	me.equip(src.createMateria("fire"));
	me.equip(src.createMateria("cure"));
	std::cout << "FINISH\n\n";
}

void	testCharacterMethods(void)
{
	std::cout << "TEST Character Methods\n";
	Character me("Iceking");
	AMateria* array[6];
	for (int i = 0; i != 6; i += 2) {
		array[i] = new Ice();
		array[i + 1] = new Cure();
	}

	for (int i = 0; i != 6; ++i) {
		me.equip(array[i]);
	}
	me.equip(array[0]);
	me.equip(array[5]);
	for (int i = 0; i != 5; ++i) {
		me.use(i, me);
	}
	for (int i = 0; i != 5; ++i) {
		me.unequip(i);
	}
	std::cout << "FINISH\n\n";
}

void	testMateriaSourceCtor(void)
{
	IMateriaSource* src;

	std::cout << "TEST MateriaSource Default\n";
	src = new MateriaSource();
	src->learnMateria(new Ice());
	delete src;
	std::cout << "FINISH\n\n";

	std::cout << "TEST MateriaSource Param\n";
	src = new MateriaSource("Mako Well");
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	std::cout << "FINISH\n\n";

	std::cout << "TEST MateriaSource Copy and Assignment\n";
	MateriaSource two(*dynamic_cast<MateriaSource*>(src));
	two.printInfo();

	MateriaSource three("Laboratory");
	three = two;
	three.printInfo();

	delete src;
	std::cout << "FINISH\n\n";
}
void	testCharacterCtor(void)
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
	you.printInfo();

	Character dog("Jake");
	dog = you;
	dog.unequip(1);

	delete me;
	std::cout << "FINISH\n\n";
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
	std::cout << "TEST from subject\n";
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
	std::cout << "FINISH\n\n";
}

int	main(void)
{
	std::cout << "STARTING TESTS\n\n";
	testFromSubject();
	testCharacterCtor();
	testCharacterMethods();
	testMateriaSourceCtor();
	testMateriaSourceMethods();
	testOverfill();
	return 0;
}



// Give better messages when materia is already assigned