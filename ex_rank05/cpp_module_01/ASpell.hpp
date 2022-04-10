#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {

protected:
    std::string _name;
    std::string _effects;
    ASpell(std::string const &name, std::string const &effects);

public:

    virtual ~ASpell();

    std::string const &getName() const;
    std::string const &getEffects() const;

    virtual ASpell *clone() const = 0;

    void launch(ATarget const &target) const;
};

#endif
