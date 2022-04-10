#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
    std::string _type;

    ATarget(std::string const &type);

public:
    std::string const &getType() const;

    virtual ATarget *clone() const = 0;

    void getHitBySpell(ASpell const &spell) const;

    virtual ~ATarget();
};

#endif
