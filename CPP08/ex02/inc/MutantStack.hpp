#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : std::stack
{
	private:

	public:

	MutantStack();
	MutantStack(MutantStack const& copy);
	MutantStack & operator=(MutantStack copy);
	~MutantStack();

	class iterator
	{
		iterator operator++();
		iterator operator--();
		iterator operator==(iterator right);
		T operator*()

	}
};

#endif