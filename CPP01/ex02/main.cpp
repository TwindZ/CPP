#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;

int main()
{
	string hello = "HI THIS IS BRAIN";
	string *helloPtr = &hello;
	string &helloRef = hello;

	cout << "hello adress\t: " << &hello << endl;
	cout << "helloPtr adress\t: "<< &helloPtr << endl;
	cout << "helloRef adress\t: "<< &helloRef << endl;
	
	cout << "hello data\t: " << hello << endl;
	cout << "*helloPtr data\t: " << *helloPtr << endl;
	cout << "helloRef data\t: " << helloRef << endl;

}
