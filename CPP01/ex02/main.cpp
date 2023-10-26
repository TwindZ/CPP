#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;

int main()
{
	string str = "HI THIS IS BRAIN";
	string *stringPtr = &str;
	string &stringRef = str;

	cout << "string address\t\t: " << &str << endl;
	cout << "stringPtr address\t: "<< &stringPtr << endl;
	cout << "stringRef address\t: "<< &stringRef << endl;
	cout << endl;
	cout << "**************************************************"<< endl;
	cout << endl;
	cout << "string data\t: " << str << endl;
	cout << "*stringPtr data\t: " << *stringPtr << endl;
	cout << "stringRef data\t: " << stringRef << endl;
	cout << endl;
	cout << "**************************************************"<< endl;

	cout << endl;
	cout << "string address\t\t: " << &str << endl;
	cout << "stringPtr address\t: "<< &stringPtr << endl;
	cout << "stringRef address\t: "<< &stringRef << endl;
	cout << endl;
	cout << "**************************************************"<< endl;

	cout << endl;
	str = "salut";
	cout << "string data\t: " << str << endl;
	*stringPtr = "bonjour";
	cout << "*stringPtr data\t: " << str << endl;
	stringRef = "allo";
	cout << "stringRef data\t: " << str << endl;
}
