#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

using std::stack;

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

	MutantStack() : stack<T> (){};
	MutantStack(MutantStack const& copy) : stack<T>(copy){};
	MutantStack & operator=(MutantStack const& copy){
		*this = stack<T>::operator=(copy);
		return *this;
	};
	~MutantStack(){};

	typedef typename stack<T>::container_type::iterator iterator;
	iterator begin() { return (stack<T>::c.begin()); };
	iterator end() { return (stack<T>::c.end()); };
};

#endif