#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <stdexcept>
# include <ctime>
# include <limits>

template <typename container, typename pairs_container>
class PmergeMe
{
	public:

		typedef typename container::iterator container_it;
		PmergeMe();
		PmergeMe(PmergeMe const& Copy);
		PmergeMe & operator=(PmergeMe const& Copy);
		~PmergeMe();

		void sort(int argc, char **argv);
		void printVector();
		void printSortedVector(double time_elapsed);
		void printJacob();
	
	private:

		void convertToVectorPair(int argc, char **argv);
		void sortEachPair();
		void sortBySecond();
		void addSecondToSorted();
		void binaryInsertion(unsigned int first);
		PmergeMe<container, pairs_container>::container_it findRangeMiddle(container_it begin, container_it end);
		void precisionInsert(unsigned int first, container_it middle);
		void mergeToSorted();
		void mergeStragglerToSorted();
		void sortVector(int argc, char **argv);
		void createJacobNumber(size_t size);
		void createJacobVector(size_t size);
		size_t insertByJacob();
		void insertRemain(size_t i);
		void parseArgv(char **argv);
		std::exception invalidArgumentException();
		std::exception maxUnsignedIntException();
		void checkMaxUInt(unsigned long number);
		void isSorted();
		void vectorAlgo();


		pairs_container	_pairs;
		container 		_sortedContainer;
		container		_jacobsthal;
		unsigned int	_straggler;
		bool			_stragglerStatus;
};

# include "../srcs/PmergeMe.tpp"

#endif