#ifndef PMERGEME_TPP
# define PMERGEME_TPP

using std::cout;
using std::endl;

template <typename container, typename pairs_container>
PmergeMe<container, pairs_container>::PmergeMe():
_pairs(), _sortedContainer(), _jacobsthal(), _straggler(), _stragglerStatus(false), _type()
{
	cout << "PmergeMe constructor call" << endl;
}

template <typename container, typename pairs_container>
PmergeMe<container, pairs_container>::PmergeMe(std::string type):
_pairs(), _sortedContainer(), _jacobsthal(), _straggler(), _stragglerStatus(false), _type(type)
{
	cout << "Overload PmergeMe constructor call" << endl;
}

template <typename container, typename pairs_container>
PmergeMe<container, pairs_container>::PmergeMe(PmergeMe const& copy)
{
	cout << "PmergeMe copy constructor call" << endl;
	*this = copy;
}

template <typename container, typename pairs_container>
PmergeMe<container, pairs_container> & PmergeMe<container, pairs_container>::operator=(PmergeMe const& copy)
{
	cout << "PmergeMe assignement call" << endl;
	if(this == &copy)
		return *this;
	_pairs = copy._pairs;
	_sortedContainer = copy._sortedContainer;
	_jacobsthal = copy._jacobsthal;
	_straggler = copy._straggler;
	_stragglerStatus = copy._stragglerStatus;
	return *this;
}

template <typename container, typename pairs_container>
PmergeMe<container, pairs_container>::~PmergeMe()
{
	cout << "PmergeMe destructor call" << endl;
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::checkMaxUInt(unsigned long const& number)const
{
	if(number > std::numeric_limits<unsigned int>::max())
		maxUnsignedIntException();
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::parseArgv(char **argv)const
{
	for(int i = 1; argv[i]; i++)
	{
		for(int j = 0; argv[i][j]; j++)
			if(!std::isdigit(argv[i][j]))
				invalidArgumentException();
		checkMaxUInt(std::atol(argv[i]));
	}
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::convertToVectorPair(int const& argc, char **argv)
{
	for(int i = 1; i <= argc - 1; i += 2)
	{
		if(argv[i + 1])
			_pairs.push_back(std::pair<unsigned int, unsigned int>
				(std::atol(argv[i]), std::atol(argv[i + 1])));
		else
		{
			_straggler = std::atol(argv[i]);
			_stragglerStatus = true;
		}	
	}
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::sortEachPair()
{
	for(size_t i = 0; i < _pairs.size(); i++)
	{
		if(_pairs[i].first > _pairs[i].second)
			std::swap(_pairs[i].first, _pairs[i].second);
	}
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::sortBySecond()
{
	size_t i = 0;
	
	//need while loop because of the reset i = 0
	while(i < _pairs.size() - 1) 
	{
		if(_pairs[i].second > _pairs[i + 1].second)
		{
			std::swap(_pairs[i], _pairs[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::addSecondToSorted()
{
	for(size_t i = 0; i < _pairs.size(); i++)
		_sortedContainer.push_back(_pairs[i].second);
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::createJacobVector(size_t const& size)
{
	_jacobsthal.push_back(1);
	_jacobsthal.push_back(3);
	for(size_t i = 2; i < size; i++)
		_jacobsthal.push_back(_jacobsthal[i - 1] + (2 * _jacobsthal[i - 2]));
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::precisionInsert(unsigned int const& first, container_it const& middle)
{
	if(first < *middle && first > *(middle - 1))
		_sortedContainer.insert(middle, first);
	else if(first < *middle && first <= *(middle - 1))
		_sortedContainer.insert(middle - 1, first);
	else
		_sortedContainer.insert(middle + 1, first);
}

template <typename container, typename pairs_container>
typename PmergeMe<container, pairs_container>::container_it
PmergeMe<container, pairs_container>::findRangeMiddle(container_it const& begin, container_it const& end)const
{
	std::ptrdiff_t range = std::distance(begin, end);
	return begin + range / 2;
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::binaryInsertion(unsigned int const& first)
{
	PmergeMe<container, pairs_container>::container_it begin = _sortedContainer.begin();
	PmergeMe<container, pairs_container>::container_it end = _sortedContainer.end();
	PmergeMe<container, pairs_container>::container_it middle;

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

template <typename container, typename pairs_container>
size_t PmergeMe<container, pairs_container>::insertByJacob()
{
	size_t i;
	_sortedContainer.insert(_sortedContainer.begin(), _pairs[0].first);
	for(i = 1; _jacobsthal[i] <= _pairs.size() ; i++)
		for(unsigned int j = _jacobsthal[i]; j > _jacobsthal[i - 1]; j--)
			binaryInsertion(_pairs[j - 1].first);
	return i;
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::insertRemain(size_t const& i)
{
	if(_pairs.size() > _jacobsthal[i - 1])
		for(unsigned int j = _pairs.size(); j > _jacobsthal[i - 1]; j--)
			binaryInsertion(_pairs[j - 1].first);
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::mergeToSorted()
{
	createJacobVector(_pairs.size());
	insertRemain(insertByJacob());
	if(_stragglerStatus == true)
		binaryInsertion(_straggler);
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::algo()
{
	sortEachPair();
	sortBySecond();
	addSecondToSorted();
	mergeToSorted();
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::sortNumbers(int const& argc, char **argv)
{

	convertToVectorPair(argc, argv);
	clock_t time = std::clock();
	algo();
	printUnsorted(argv);
	printSorted(static_cast<double> (std::clock() - time)/ CLOCKS_PER_SEC);
	isSorted();
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::sort(int const& argc, char **argv)
{
	try
	{
		parseArgv(argv);
		sortNumbers(argc, argv);
	}
	catch(std::exception const& e)
	{
		cout << e.what() << endl;
	}
}
template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::printUnsorted(char **argv)const
{
	cout << "Unsorted :" << endl;
	for(int i = 1; argv[i]; i++)
	{
		std:: string arg(argv[i]);
		cout << arg << ", ";
	}	
	cout << endl;
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::printSorted(double const& time_elapsed)const
{
	cout << "Sorted : " << endl;
	for(size_t i = 0; i < _sortedContainer.size(); i++)
		cout << _sortedContainer[i] <<  ", " ;
	cout << endl;
cout << _type << " sorted in : " << std::fixed << time_elapsed << " seconds." << endl;}

template <typename container, typename pairs_container>
std::exception PmergeMe<container, pairs_container>::invalidArgumentException()const
{
	throw std::invalid_argument("Error : Invalid argument.");
}

template <typename container, typename pairs_container>
std::exception PmergeMe<container, pairs_container>::maxUnsignedIntException()const
{
	throw std::invalid_argument("Error : Invalid unsigned int");
}

//debug function

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::printPairs()const
{
	for(size_t i = 0; i < _pairs.size(); i++)
		cout << "First : " << _pairs[i].first << " Second : " << _pairs[i].second << endl;
	cout << "Straggler : " << _straggler << endl;
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::printJacob()const
{
	for(size_t i = 0; i < _jacobsthal.size(); i++)
		cout << "Jacob number : " << _jacobsthal[i] <<  ", " ;
	cout << endl;
}

template <typename container, typename pairs_container>
void PmergeMe<container, pairs_container>::isSorted()const
{
	for(size_t i = 0; i < _sortedContainer.size() - 1; i++)
		if(_sortedContainer[i] > _sortedContainer[i + 1])
			cout << endl << "########## Error : Sorting fail.##########" << endl << endl;
	if(_sortedContainer.size() != (_pairs.size() * 2) + _stragglerStatus ? 1 : 0)
		cout << endl << "##########Error : Missing numbers############" << endl << endl;
}

#endif