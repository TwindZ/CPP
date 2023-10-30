#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;

int main()
{
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	cout << "string address\t\t: " << &str << endl;
	cout << "stringPTR address\t: "<< stringPTR << endl;
	cout << "stringREF address\t: "<< &stringREF << endl;
	cout << endl;
	cout << "**************************************************"<< endl;

	cout << endl;
	cout << "string value\t\t: " << str << endl;
	cout << "*stringPTR value\t: " << *stringPTR << endl;
	cout << "stringREF value\t\t: " << stringREF << endl;
	cout << endl;
	cout << "**************************************************"<< endl;

	cout << endl;
	str = "salut";
	cout << "str value changed by str\t: " << str << endl;
	*stringPTR = "bonjour";
	cout << "str value changed by *stringPTR\t: " << str << endl;
	stringREF = "allo";
	cout << "str value changed by stringREF\t: " << str << endl;
	return 0;
}
