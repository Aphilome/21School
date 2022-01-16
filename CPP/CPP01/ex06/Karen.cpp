#include "Karen.hpp"

levels Karen::enumLevelConverter(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::string levelStr[] = { "DEBUG" , "INFO", "WARNING", "ERROR" };
	levels level = lNone;
	for (int i = 0; i < 4; ++i)
		if (levelStr[i] == str)
		{
			level = (levels)(i + 1);
			break;
		}
	return level;
}

Karen::Karen(levels currentLevel)
{
	_minLevel = currentLevel;
}

void Karen::complain(std::string level)
{
	levels msgLevel = enumLevelConverter(level);
	if (msgLevel < _minLevel)
		return;

	switch (msgLevel)
	{
		case lDebug:
		{
			debug();
			break;
		}
		case lInfo:
		{
			info();
			break;
		}
		case lWarning:
		{
			warning();
			break;
		}
		case lError:
		{
			error();
			break;
		}
		case lNone:
			return;
	}
}

void Karen::debug(void)
{
	std::cout	<< "[ DEBUG ] "
				<< std::endl;
	std::cout	<< "I love to get extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
				 "just love it!"
				 << std::endl << std::endl;
}

void Karen::info(void)
{
	std::cout << "[ INFO ] " << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You "
				 "don’t put enough! If you did I would not have to ask for "
				 "it!"
				 << std::endl << std::endl;
}

void Karen::warning(void)
{
	std::cout << "[ WARNING ] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve "
				 "been coming here for years and you just started working "
				 "here last month."
				 << std::endl << std::endl;
}

void Karen::error(void)
{
	std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now."
			  << std::endl
			  << std::endl;
}
