#include <iostream>
#include <vector>
#include <deque>
#include "../inc/PmergeMe.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	if(argc < 3 || argc > 4001)
	{
		cerr << "Usage : ./PmergeMe <numbers (ex : 2 6 8 4 77 5 999)>" << endl;
		cerr << "Min 2 numbers Max 4000 numbers" << endl;
		return -1;
	}
	PmergeMe<std::vector<unsigned long>, std::vector
	< std::pair <unsigned long, unsigned long> > > pmergeMe2("Vector");
	pmergeMe2.sort(argc, argv);
	PmergeMe<std::deque<unsigned long>, std::deque
	< std::pair <unsigned long, unsigned long> > > pmergeMe("Deque");
	pmergeMe.sort(argc, argv);
}