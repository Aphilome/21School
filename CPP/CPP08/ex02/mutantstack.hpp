#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack<T>() { };
	MutantStack<T>(const MutantStack<T> &src)
	{
		*this = src;
	};

	MutantStack<T>	&operator=( const MutantStack<T> &src )
	{
		return (std::stack<T>::operator=(src));
	};

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin()
	{
		return this->c.begin();
	}

	iterator	end()
	{
		return this->c.end();
	}

	~MutantStack<T>()
	{
	};
};

#endif
