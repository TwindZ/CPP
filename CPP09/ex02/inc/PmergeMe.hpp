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

		void sort(int const& argc, char **argv);
	
	private:

		PmergeMe();

		void convertToVectorPair(int const& argc, char **argv);
		void sortEachPair();
		void sortBySecond();
		void addSecondToSorted();
		void binaryInsertion(unsigned int const& first);

		PmergeMe<container, pairs_container>::container_it
		findRangeMiddle(container_it const& begin, container_it const& end)const;

		void precisionInsert(unsigned int const& first, container_it const& middle);
		void mergeToSorted();
		void sortNumbers(int const& argc, char **argv);
		void createJacobVector(size_t const& size);
		size_t insertByJacob();
		void insertRemain(size_t const& i);
		void parseArgv(char **argv)const;
		void checkMaxUInt(unsigned long const& number)const;
		void algo();
		void isSorted()const;
		void printSorted(double const& time_elapsed)const;
		void printUnsorted(char **argv)const;
		void printPairs()const;
		void printJacob()const;
		std::exception invalidArgumentException()const;
		std::exception maxUnsignedIntException()const;


		pairs_container				_pairs;
		container 					_sortedContainer;
		std::vector<unsigned long>	_jacobsthal;
		unsigned int				_straggler;
		bool						_stragglerStatus;
		std::string					_type;
};

# include "../srcs/PmergeMe.tpp"

#endif