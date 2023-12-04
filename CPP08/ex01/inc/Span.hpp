#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
	private:

		size_t _size;
		std::vector<int> _span;
		
		Span();
		int findShortestSpan();
		int findLongestSpan();
		int findCurrentSpan(int a, int b);

	public:

		Span(size_t size);
		Span(Span const& Copy);
		Span & operator=(Span const& Copy);
		~Span();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void print();

		std::exception maxSizeException();
		std::exception invalidSpanException();

};

#endif