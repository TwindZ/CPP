#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain():_ideas(nullptr)
{
	cout << "Brain constructor called" << endl;
	_ideas = new string[100];
}

Brain::Brain(Brain const& copy): _ideas(nullptr)
{
	cout << "Brain copy constructor called" << endl;
	*this = copy;
}

Brain & Brain::operator=(Brain const& copy)
{
	cout << "Brain assignement called" << endl;
	if(this != &copy)
	{
		if(_ideas != nullptr)
			delete [] _ideas;
		_ideas = new string[100];
		for(int i = 0; i < 100; i++)
			_ideas[i] = copy._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	delete [] _ideas;
	cout << "Brain destructor called" << endl;
}

string const& Brain::getIdeas(int const i)const
{
	return _ideas[i];
}

void Brain::setIdea(int const i, string const& idea)
{
	_ideas[i] = idea;
}