#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

template <typename T>
void easyfind(T cont, int toFind)
{
	for(typename T::iterator it = cont.begin(); it != cont.end(); it++)
	{
		if(*it == toFind)
		{
			std::cout << "found : " << *it << std::endl;
			return;
		}
	}
	throw std::runtime_error("no occurence found");
}

#endif