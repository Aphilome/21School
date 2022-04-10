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

void Warlock::learnSpell(ASpell *spell) {
    if (spell)
    {
        _spells[spell->getName()] = spell;
    }
}

void Warlock::forgetSpell(const std::string &name) {
    std::map<std::string, ASpell *>::iterator it = _spells.find(name);
    if (it != _spells.end())
    {
        delete it->second;
        _spells.erase(it);
    }
}

void Warlock::launchSpell(const std::string &name, const ATarget &target) {
    std::map<std::string, ASpell *>::iterator it = _spells.find(name);
    if(it != _spells.end())
    {
        it->second->launch(target);
    }
}

