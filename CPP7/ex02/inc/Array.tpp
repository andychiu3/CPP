#include "Array.hpp"

/* constructor */
template<typename T>
Array<T>::Array() 
	: _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) 
	: _array(new T[n]), _size(n) {}

template<typename T>
Array<T>::Array(const Array& copy) 
	: _array(new T[copy._size]), _size(copy._size) {
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = copy._array[i];
}

template<typename T>
Array<T>::~Array() {
	delete[] _array;
}

/* operator */
template<typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	if (this != &other) {
		T*	tmp = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			tmp[i] = other._array[i];
		delete[] _array;
		_array = tmp;
		_size = other._size;
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw	outOfRange();
	return _array[index];
}

template<typename T>
const T&	Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw	outOfRange();
	return _array[index];
}

/* mandatory */
template<typename T>
unsigned int	Array<T>::size() const {
	return _size;
}
