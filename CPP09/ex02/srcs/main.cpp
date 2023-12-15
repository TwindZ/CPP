#include <iostream>
#include <vector>
#include <deque>
#include "../inc/PmergeMe.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr << "Usage : ./PmergeMe <numbers (ex : 2 6 8 4 77 5 999)>" << endl;
	}
	PmergeMe<std::deque<unsigned long>, std::deque< std::pair <unsigned long, unsigned long> > > pmergeMe;
	PmergeMe<std::vector<unsigned long>, std::vector< std::pair <unsigned long, unsigned long> > > pmergeMe2;
	pmergeMe.sort(argc, argv);
	pmergeMe2.sort(argc, argv);
}