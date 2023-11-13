#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

using std::string;

class Brain
{
	private:
		string *_idea;

	public:
		Brain();
		Brain(Brain const& Copy);
		Brain & operator=(Brain const& Copy);
		~Brain();

		string & getIdea(int const i)const;
};

#endif