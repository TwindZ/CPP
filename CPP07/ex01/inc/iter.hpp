#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>
void iter(T * array, size_t size, void (*function)(T &))
{
	for(size_t i = 0; i < size; i++)
	{
		function(array[i]);
	}
}

void patate(string & s)
{
	s = "patate";
}

template <typename T>
void add(T & s)
{
	s += 10;
}

template <typename T>
void print(T & s)
{
	cout << s << endl;
}

#endif