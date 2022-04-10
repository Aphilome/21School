#include "ATarget.hpp"

ATarget::ATarget(const std::string &type) {
    _type = type;
}

std::string const &ATarget::getType() const {
    return _type;
}

void ATarget::getHitBySpell(const ASpell &spell) const {
    std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}

ATarget::~ATarget() {

}
