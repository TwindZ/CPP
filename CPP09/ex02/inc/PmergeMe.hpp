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
	
	private:

		void convertToVectorPair(int argc, char **argv);
		void sortEachPair();
		void sortBySecond();
		void addSecondToSorted();
		void mergeFirstToSorted();
		void mergeStragglerToSorted();

		void chrono();


		std::vector< std::pair<unsigned long, unsigned long> > _vector;
		std::vector<unsigned long> _sortedVector;
		unsigned int _straggler;
};

#endif