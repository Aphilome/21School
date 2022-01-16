#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
public:
	Array<T>(): _size(0), _array(nullptr)
	{
	};

	Array<T>(unsigned int n): _size(n), _array(nullptr)
	{
		if (_size < 0)
			throw std::overflow_error("Index out of bounds");
		_array = new T[_size];
	};

	Array<T>(const Array<T> &src)
	{
		*this = src;
	}

	Array<T> &operator=(const Array<T> &src)
	{
		if (this != &src)
		{
			if (_size > 0)
				delete[] _array;
			_size = src._size;
			_array = new T[_size];
			for (int i = 0; i < _size; ++i)
				_array[i] = src[i];
		}
		return (*this);
	}

	T &operator[](const int index) const
	{
		if (index >= _size || index < 0)
			throw std::overflow_error("Index out of bounds");
		return (_array[index]);
	}

	int size() const
	{
		return (_size);
	}

	~Array<T>( void )
	{
		if (_size > 0)
			delete[] _array;
	}

private:
	int		_size;
	T		*_array;
};

#endif
