#include <iostream>
#include <vector>
#include <list>
#include "../inc/easyfind.hpp"

using std::string;
using std::cout;
using std::endl;

int main()
{
	std::vector<int> testvector;
	for (int i = 0; i < 50; i++)
		testvector.push_back(i);
	std::list<int> testlist;
	for (int i = 0; i < 50; i++)
		testlist.push_back(i);
	
	try
	{
		easyfind(testvector, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		easyfind(testlist, 45);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}