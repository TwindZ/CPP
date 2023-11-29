#include <iostream>
#include "../inc/Array.hpp"

using std::string;
using std::cout;
using std::endl;

int main()
{
	Array<string> arrayA(10);
	Array<string> arrayB(10);
	Array<int> arrayC(10);

	arrayA[8] = "salut";
	arrayB[7] = arrayA[8] + "allo";
	
	try
	{
		cout << arrayA[8] << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		cout << arrayB[7] << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	cout << arrayA.size() << endl;

	for(size_t i = 0; i < arrayC.size(); i++)
		arrayC[i] = i;
	for(size_t i = 0; i < arrayC.size(); i++)
		cout << arrayC[i] << endl;

	Array<int> arrayD(arrayC);

	for(size_t i = 0; i < arrayC.size(); i++)
		cout << arrayC[i] << endl;
	for(size_t i = 0; i < arrayC.size(); i++)
		arrayC[i] = 100;
	for(size_t i = 0; i < arrayC.size(); i++)
		cout << arrayC[i] << endl;
	for(size_t i = 0; i < arrayD.size(); i++)
		cout << arrayD[i] << endl;

	arrayD = arrayC;

	for(size_t i = 0; i < arrayD.size(); i++)
		cout << arrayD[i] << endl;

	try
	{
		cout << arrayD[20] << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}