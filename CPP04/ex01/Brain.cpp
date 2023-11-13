#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain():_idea(nullptr)
{
	_idea = new string[100];
	for(int i = 0; i < 100; i++)
		_idea[i] = "test" + std::to_string(i);
	cout << "Brain constructor called" << endl;
}

Brain::Brain(Brain const& copy): _idea(nullptr)
{
	*this = copy;
	cout << "Brain copy constructor called" << endl;
}

Brain & Brain::operator=(Brain const& copy)
{
	if(this != &copy)
	{
		if(_idea != nullptr)
			delete [] _idea;
		_idea = new string[100];
		for(int i = 0; i < 100; i++)
			_idea[i] = copy._idea[i];
		cout << "Brain assignement called" << endl;
	}
	return *this;
}

Brain::~Brain()
{
	delete [] _idea;
	cout << "Brain destructor called" << endl;
}

string & Brain::getIdea(int const i)const
{
	return _idea[i];
}