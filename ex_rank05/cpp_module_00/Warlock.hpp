#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock {

private:
    std::string _name;
    std::string _title;

    Warlock();
    Warlock(Warlock const &warlock);
    Warlock &operator=(Warlock const &warlock);

public:
    Warlock(std::string const &name, std::string const &title);
    ~Warlock();

    std::string const &getName() const;
    std::string const &getTitle() const;

    void setTitle(std::string const &title);

    void introduce() const;
};

#endif
