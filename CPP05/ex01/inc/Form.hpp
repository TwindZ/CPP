#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

using std::string;
class Form
{
	private:
		
		string const _name;
		bool _issigned;
		unsigned int gradeToSign;
		unsigned int gradeToExec;

	public:

		Form();
		Form(Form const& Copy);
		Form & operator=(Form const& Copy);
		~Form();

};

#endif