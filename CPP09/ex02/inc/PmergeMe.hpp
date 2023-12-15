#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <stdexcept>
# include <ctime>
# include <limits>


class PmergeMe
{
	public:

		typedef std::vector<unsigned long>::iterator vector_it;
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
		vector_it findRangeMiddle(vector_it begin, vector_it end);
		void precisionInsert(unsigned int first, vector_it middle);
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


		std::vector< std::pair<unsigned long, unsigned long> > _vector;
		std::vector<unsigned long> _sortedVector;
		std::vector<unsigned long> _jacobsthal;
		unsigned int _straggler;
		bool		_stragglerStatus;
};

#endif