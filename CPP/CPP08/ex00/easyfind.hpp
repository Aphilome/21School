#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int i)
{
	typename T::iterator iterator = find(container.begin(), container.end(), i);
	return (iterator);
}

#endif
