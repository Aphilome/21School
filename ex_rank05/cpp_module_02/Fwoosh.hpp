#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <string>
#include "ASpell.hpp"

class Fwoosh : public ASpell{

public:
    Fwoosh();
    virtual ASpell *clone() const;
};

#endif
