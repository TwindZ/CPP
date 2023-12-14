#include "../inc/PmergeMe.hpp"

using std::cout;
using std::endl;

PmergeMe::PmergeMe():_vector(), _sortedVector(), _straggler()
{
	cout << "PmergeMe constructor call" << endl;
}

PmergeMe::PmergeMe(PmergeMe const& copy)
{
	cout << "PmergeMe copy constructor call" << endl;
	*this = copy;
}

PmergeMe & PmergeMe::operator=(PmergeMe const& copy)
{
	cout << "PmergeMe assignement call" << endl;
	if(this == &copy)
		return *this;
	//TODO /* ADD PRIVATES */
	return *this;
}

PmergeMe::~PmergeMe()
{
	cout << "PmergeMe destructor call" << endl;
}

void PmergeMe::convertToVectorPair(int argc, char **argv)
{
	for(int i = 1; i <= argc; i += 2)
	{
		if(argv[i + 1])
		{
			std::pair<unsigned int, unsigned int> pair(std::atol(argv[i]), std::atol(argv[i + 1]));
			_vector.push_back(pair);
		}	
		else
			_straggler = std::atol(argv[i]);
	}
}

void PmergeMe::sortEachPair()
{
	for(size_t i = 0; i < _vector.size(); i++)
	{
		if(_vector[i].first > _vector[i].second)
			std::swap(_vector[i].first, _vector[i].second);
	}
}

void PmergeMe::sortBySecond()
{
	size_t i = 0;
	
	while(i < _vector.size() - 1)
	{
		if(_vector[i].second > _vector[i + 1].second)
		{
			std::swap(_vector[i], _vector[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void PmergeMe::addSecondToSorted()
{
	for(size_t i = 0; i < _vector.size(); i++)
		_sortedVector.push_back(_vector[i].second);
}

void PmergeMe::mergeFirstToSorted()
{
	std::vector<unsigned long>::iterator it;
	for(size_t i = 0; i < _vector.size(); i++)
	{
		for(it = _sortedVector.begin(); it < _sortedVector.end(); it++)
		{
			if(_vector[i].first < *it)
			{
				_sortedVector.insert(it, _vector[i].first);
				break;
			}	
		}
	}
}

void PmergeMe::mergeStragglerToSorted()
{
	std::vector<unsigned long>::iterator it;
	for(it = _sortedVector.begin(); it < _sortedVector.end(); it++)
	{
		if(_straggler < *it)
		{
			_sortedVector.insert(it, _straggler);
			break;
		}	
	}
}

void PmergeMe::sortVector(int argc, char **argv)
{
	convertToVectorPair(argc, argv);
	sortEachPair();
	printVector();
	sortBySecond();
	addSecondToSorted();
	mergeFirstToSorted();
	mergeStragglerToSorted();
	printVector();
	findInsertionIndex(89);
	printSortedVector();
}

vector_it PmergeMe::findRangeMiddle(vector_it begin, vector_it end)
{
	std::ptrdiff_t range = std::distance(begin, end);
	return begin + range / 2;
}

void PmergeMe::findInsertionIndex(unsigned int first)
{
	vector_it begin = _sortedVector.begin();
	vector_it end = _sortedVector.end();
	vector_it middle;

	while(begin != end - 1)
	{
		middle = findRangeMiddle(begin, end);
		if(first < *middle)
			end = middle;
		else
			begin = middle;
	}
	if(first < *middle)
		_sortedVector.insert(middle, first);
	else
		_sortedVector.insert(middle + 1, first);
}

void PmergeMe::sort(int argc, char **argv)
{
	
	//TODO parseArgv();
	sortVector(argc, argv);
}

void PmergeMe::printVector()
{
	for(size_t i = 0; i < _vector.size(); i++)
		cout << "First : " << _vector[i].first << " Second : " << _vector[i].second << endl;
	cout << "Straggler : " << _straggler << endl;
	
}

void PmergeMe::printSortedVector()
{
	cout << _sortedVector[0];
	for(size_t i = 1; i < _sortedVector.size(); i++)
		cout <<  ", " << _sortedVector[i];
	cout << endl;
	
}