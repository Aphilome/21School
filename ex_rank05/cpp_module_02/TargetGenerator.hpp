#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
private:
	std::map<std::string, ATarget *> targets;
	TargetGenerator(TargetGenerator const &targetGenerator);
	TargetGenerator &operator=(TargetGenerator const &targetGenerator);

public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget *target);
	void forgetTargetType(std::string const &name);
	ATarget* createTarget(std::string const &name);
};

#endif
