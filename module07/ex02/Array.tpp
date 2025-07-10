#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _size(0), _array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n), _array(new T[n])
{
	for (unsigned int i = 0; i < n; ++i)
		_array[i] = T();
}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size), _array(new T[other._size])
{
	for (unsigned int i = 0; i < this->_size; ++i)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete [] this->_array;
		this->_size = other._size;
		this->_array = new T[other._size];
		for (unsigned int i = 0; i < this->_size; ++i)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::exception();
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->_size);
}
