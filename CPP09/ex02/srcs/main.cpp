#include <iostream>
#include "../inc/PmergeMe.hpp"

// J(n)=J(n−1)+2⋅J(n−2)

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr << "Usage : ./PmergeMe <numbers (ex : 2 6 8 4 77 5 999)>" << endl;
	}
	PmergeMe pmergeMe;
	pmergeMe.sort(argc - 1, argv);
}