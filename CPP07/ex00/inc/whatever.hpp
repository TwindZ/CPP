#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
void	swap(T & valueA, T & valueB) {
	T tempValue;

	tempValue = valueA;
	valueA = valueB;
	valueB = tempValue;
}

template <typename T>
T const& min(T & valueA, T & valueB) {
	if(valueA < valueB)
		return valueA;
	return valueB;
}

template <typename T>
T const& max(T & valueA, T & valueB) {
	if(valueA > valueB)
		return valueA;
	return valueB;
}

#endif