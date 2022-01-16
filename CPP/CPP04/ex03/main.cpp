#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* aphilome = new Character("Aphilome");

	aphilome->equip(src->createMateria("ice"));
	aphilome->equip(src->createMateria("cure"));

	ICharacter* tbirdper = new Character("Tbirdper");

	aphilome->use(0, *tbirdper);
	aphilome->use(0, *tbirdper);
	aphilome->use(1, *tbirdper);

	aphilome->equip(src->createMateria("ice"));
	aphilome->equip(src->createMateria("ice"));
	aphilome->equip(src->createMateria("ice"));
	aphilome->equip(src->createMateria("ice"));
	aphilome->equip(src->createMateria("ice"));

	ICharacter* you = new Character(*(Character*)aphilome);
	aphilome->use(0, *tbirdper);
	you->use(0, *tbirdper);

	delete tbirdper;
	delete aphilome;
	delete you;
	delete src;

	std::cout << "♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡" <<std::endl;
	return 0;

}
