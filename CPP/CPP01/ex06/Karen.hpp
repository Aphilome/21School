#pragma once
#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

enum levels {
	lNone = 0,
	lDebug = 1,
	lInfo = 2,
	lWarning = 3,
	lError = 4,
};

class Karen{
public:
	static levels enumLevelConverter(std::string str);

	Karen(levels currentLevel);
	void complain( std::string level );
private:
	levels _minLevel;

	void debug();
	void info();
	void warning();
	void error();
};


#endif
