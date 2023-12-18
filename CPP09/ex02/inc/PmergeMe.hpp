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
		PmergeMe(std::string type);
		PmergeMe(PmergeMe const& Copy);
		PmergeMe & operator=(PmergeMe const& Copy);
		~PmergeMe();

		void sort(int argc, char **argv);
	
	private:

		PmergeMe();
		void convertToVectorPair(int argc, char **argv);
		void sortEachPair();
		void sortBySecond();
		void addSecondToSorted();
		void binaryInsertion(unsigned int first);

		PmergeMe<container, pairs_container>::container_it
		findRangeMiddle(container_it begin, container_it end);

		void precisionInsert(unsigned int first, container_it middle);
		void mergeToSorted();
		void sortNumber(int argc, char **argv);
		void createJacobNumber(size_t size);
		void createJacobVector(size_t size);
		size_t insertByJacob();
		void insertRemain(size_t i);
		void parseArgv(char **argv);
		void checkMaxUInt(unsigned long number);
		void isSorted();
		void algo();
		void printSorted(double time_elapsed);
		void printUnsorted(char **argv);
		void printPairs();
		void printJacob();
		std::exception invalidArgumentException();
		std::exception maxUnsignedIntException();


		pairs_container				_pairs;
		container 					_sortedContainer;
		std::vector<unsigned long>	_jacobsthal;
		unsigned int				_straggler;
		bool						_stragglerStatus;
		std::string					_type;
};

# include "../srcs/PmergeMe.tpp"

#endif