#pragma once

#include <iostream>

template<typename T>
void	swap(T& a, T&b) {
	T	tmp = b;
	b = a;
	a = tmp;
}

template<typename T>
const T&	min(const T& a, const T& b) {
	if (a >= b)
		return b;
	return a;
}

template<typename T>
T& max(T& a, T& b) {
	if (a <= b)
		return b;
	return a;
}
