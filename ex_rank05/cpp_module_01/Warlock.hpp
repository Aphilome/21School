#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock {

private:
    std::string _name;
    std::string _title;

    Warlock();
    Warlock(Warlock const &warlock);
    Warlock &operator=(Warlock const &warlock);
    //new01
    std::map<std::string, ASpell *> _spells;

public:
    Warlock(std::string const &name, std::string const &title);
    ~Warlock();

    std::string const &getName() const;
    std::string const &getTitle() const;

    void setTitle(std::string const &title);

    void introduce() const;

    //new01
    void learnSpell(ASpell *spell);
    void forgetSpell(std::string const &name);
    void launchSpell(std::string const &name, ATarget const &target);
};

#endif
