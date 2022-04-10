#include "TargetGenerator.hpp"



void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string &name)
{
	std::map<std::string, ATarget *>::iterator it = targets.find(name);
	if (it != targets.end())
	{
		delete it->second;
		targets.erase(it);
	}
}

ATarget *TargetGenerator::createTarget(const std::string &name)
{
	std::map<std::string, ATarget *>::iterator it = targets.find(name);
	if (it != targets.end())
		return it->second->clone();
	return nullptr;
}

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{

}
