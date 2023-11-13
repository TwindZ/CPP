#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

using std::string;

class Brain
{
	private:
		
		string *_ideas;

	public:
		Brain();
		Brain(string idea);
		Brain(Brain const& Copy);
		Brain & operator=(Brain const& Copy);
		virtual ~Brain();

		string & getIdeas(int const i)const;
		void setIdea(int i, string idea);
};

#endif