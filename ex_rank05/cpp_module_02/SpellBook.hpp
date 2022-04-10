#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <map>
#include "ASpell.hpp"

class SpellBook
{
private:
	std::map<std::string, ASpell *> spells;
	SpellBook(SpellBook const &spellBook);
	SpellBook &operator=(SpellBook const &spellBook);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string const &name);
	ASpell* createSpell(std::string const &name);
};

#endif
