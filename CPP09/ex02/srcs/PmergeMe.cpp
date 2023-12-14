#include "../inc/PmergeMe.hpp"

using std::cout;
using std::endl;

PmergeMe::PmergeMe():_vector(), _sortedVector(), _straggler(), _stragglerStatus(false)
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
		{
			_straggler = std::atol(argv[i]);
			_stragglerStatus = true;
		}	
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

vector_it PmergeMe::findRangeMiddle(vector_it begin, vector_it end)
{
	std::ptrdiff_t range = std::distance(begin, end);
	return begin + range / 2;
}

void PmergeMe::precisionInsert(unsigned int first, vector_it middle)
{
	if(first < *middle && first > *(middle - 1))
			_sortedVector.insert(middle, first);
	else if(first < *middle && first <= *(middle - 1))
		_sortedVector.insert(middle - 1, first);
	else
		_sortedVector.insert(middle + 1, first);
}

void PmergeMe::binaryInsertion(unsigned int first)
{
	vector_it begin = _sortedVector.begin();
	vector_it end = _sortedVector.end();
	vector_it middle;

	while(begin != end - 1)
	{
		middle = findRangeMiddle(begin, end);
		if(first > *middle)
			begin = middle;
		else
			end = middle;
	}
	precisionInsert(first, middle);
}

void PmergeMe::createJacobVector(size_t size)
{
	for(size_t i = 1; i < size; i++)
	{
		if(i == 1)
		{
			_jacobsthal.push_back(1);
			_jacobsthal.push_back(3);
		}	
		else
			_jacobsthal.push_back(_jacobsthal[i - 1] + (2 * _jacobsthal[i - 2]));
	}
}

size_t PmergeMe::insertByJacob()
{
	size_t i;
	for(i = 0; _jacobsthal[i] <= _vector.size() ; i++)
		for(unsigned int j = _jacobsthal[i]; j > _jacobsthal[i - 1]; j--)
			binaryInsertion(_vector[j - 1].first);
	return i;
}

void PmergeMe::insertRemain(size_t i)
{
	if(_vector.size() > _jacobsthal[i - 1])
		for(unsigned int j = _vector.size(); j > _jacobsthal[i - 1]; j--)
			binaryInsertion(_vector[j - 1].first);
}

void PmergeMe::mergeToSorted()
{
	createJacobVector(_vector.size());
	insertRemain(insertByJacob());
	if(_stragglerStatus == true)
		binaryInsertion(_straggler);
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
						printSortedVector();
	mergeToSorted();
						printVector();
	// findInsertionIndex(89);
						printSortedVector();
						// printJacob();
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
	for(size_t i = 0; i < _sortedVector.size(); i++)
		cout << _sortedVector[i] <<  ", " ;
	cout << endl;
	
}

void PmergeMe::printJacob()
{
	for(size_t i = 0; i < _jacobsthal.size(); i++)
		cout << _jacobsthal[i] <<  ", " ;
	cout << endl;
	
}