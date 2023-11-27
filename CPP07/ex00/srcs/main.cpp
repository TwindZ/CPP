#include <iostream>
#include "../inc/whatever.hpp"

using std::string;
using std::cout;
using std::endl;

int main()
{
	string a = "allo" ;
	string b = "bonjour" ;
	int c = 15;
	int d = 7;
	float e = 2.6;
	float f = 5.4;
	


	
	cout << "String A : " << a << endl;
	cout << "String B : " << b << endl;
	swap(a , b);
	cout << "String A : " << a << endl;
	cout << "String B : " << b << endl;
	cout << endl << "###################################" << endl << endl;

	cout << "String C : " << c << endl;
	cout << "String D : " << d << endl;
	swap(c , d);
	cout << "String C : " << c << endl;
	cout << "String D : " << d << endl;
	cout << endl << "###################################" << endl << endl;

	cout << "String E : " << e << endl;
	cout << "String F : " << f << endl;
	swap(e , f);
	cout << "String E : " << e << endl;
	cout << "String F : " << f << endl;
	cout << endl << "###################################"<< endl << endl;

	cout << "Max : " << max(a, b) << endl;
	cout << "Max : " << max(c, d) << endl;
	cout << "Max : " << max(e, f) << endl;
	cout << endl << "###################################"<< endl << endl;

	cout << "Min : " << min(a, b) << endl;
	cout << "Min : " << min(c, d) << endl;
	cout << "Min : " << min(e, f) << endl;

	return (0);
}