#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>

typedef std::vector<unsigned long>::iterator vector_it;

class PmergeMe
{
	public:

		PmergeMe();
		PmergeMe(PmergeMe const& Copy);
		PmergeMe & operator=(PmergeMe const& Copy);
		~PmergeMe();

		void sort(int argc, char **argv);
		void printVector();
		void printSortedVector();
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
		void chrono();


		std::vector< std::pair<unsigned long, unsigned long> > _vector;
		std::vector<unsigned long> _sortedVector;
		std::vector<unsigned long> _jacobsthal;
		unsigned int _straggler;
		bool		_stragglerStatus;
};

#endif