#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) {
    _name = name;
    _effects = effects;
}

std::string const &ASpell::getName() const {
    return _name;
}

std::string const &ASpell::getEffects() const {
    return _effects;
}

void ASpell::launch(const ATarget &target) const {
    target.getHitBySpell((*this));
}

ASpell::~ASpell() {

}

