#pragma once
#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void	iter(T *array, int size, void (*func)(T &element))
{
	for (int i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

#endif
