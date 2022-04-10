#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) {
    _name = name;
    _title = title;
    std::cout <<_name << ": This looks like another boring day."<<std::endl;
}

std::string const &Warlock::getName() const {
    return _name;
}

std::string const &Warlock::getTitle() const {
    return _title;
}

void Warlock::setTitle(const std::string &title) {
    _title = title;
}

void Warlock::introduce() const {
    std::cout <<_name << ": I am " <<_name << ", " <<_title << "!" <<std::endl;
}

Warlock::~Warlock() {
    std::cout <<_name << ": My job here is done!"<<std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    book.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &name)
{
    if (&name == nullptr)
		return;
	book.forgetSpell(name);
}

void Warlock::launchSpell(const std::string &name, const ATarget &target)
{
    if(&name == nullptr || &target == nullptr)
		return;
	ASpell *spell = book.createSpell(name); // помещает в переменную spell
	// только что созданное (возвращенное) из книги заклинание
	if (spell != nullptr)
	{
		spell->launch(target);
		delete spell;
	}
}

