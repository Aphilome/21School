#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_learning[i] != nullptr && src->getType() == _learning[i]->getType())
		{
			delete (src);
			return ;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		if (_learning[i] == nullptr)
		{
			_learning[i] = src;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; ++i)
		if (_learning[i] != nullptr && type == _learning[i]->getType())
		{
			return _learning[i]->clone();
			break;
		}
	return (nullptr);
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_learning[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_learning[i] != nullptr)
			delete (_learning[i]);
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return *this;
	for (int i = 0; i < 4; ++i)
	{
		if (_learning[i] != nullptr)
			delete (_learning[i]);
		_learning[i] = nullptr;
		if (src._learning[i] != nullptr)
			_learning[i] = src._learning[i]->clone();
	}
	return (*this);
}
