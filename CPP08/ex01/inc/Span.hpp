#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>


class Span
{
	private:

		size_t _size;
		std::vector<int> _span;
		
		Span();
		uint32_t findCurrentSpan(int const& a, int const& b)const;
		uint32_t findShortestSpan()const;

	public:

		Span(size_t size);
		Span(Span const& Copy);
		Span & operator=(Span const& Copy);
		~Span();

		uint32_t shortestSpan()const;
		uint32_t longestSpan()const;
		void print();
		void addNumber(int number);
		void addNumber(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd);

		std::exception maxSizeException()const;
		std::exception invalidSpanException()const;

};

#endif