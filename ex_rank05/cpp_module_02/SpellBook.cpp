#include "SpellBook.hpp"

SpellBook::SpellBook() { }

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const std::string &name)
{
	std::map<std::string, ASpell *>::iterator it = spells.find(name);
	if (it != spells.end())
	{
		delete it->second;
		spells.erase(it);
	}
}

ASpell *SpellBook::createSpell(const std::string &name)
{
	std::map<std::string, ASpell *>::iterator it = spells.find(name);
	if (it != spells.end())
		return it->second->clone();
	return nullptr;
}
