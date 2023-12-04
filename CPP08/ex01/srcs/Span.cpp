#include "../inc/Span.hpp"
#include <limits>

using std::cout;
using std::endl;

Span::Span()
{
	cout << "Span constructor call" << endl;
}

Span::Span(size_t size)
{
	cout << "overload Span constructor call" << endl;
	_size = size;
}

Span::Span(Span const& copy)
{
	cout << "Span copy constructor call" << endl;
	*this = copy;
}

Span & Span::operator=(Span const& copy)
{
	cout << "Span assignement call" << endl;
	if(this != &copy)
	{
		_span = copy._span;
		_size = copy._size;
	}
	return *this;
}

Span::~Span()
{
	cout << "Span destructor call" << endl;
}

void Span::addNumber(int number)
{
	if(_span.size() < _size)
		_span.push_back(number);
	else
		maxSizeException();
}

int Span::findCurrentSpan(int a, int b)
{
	if(a - b < 0)
		return (a - b) * -1;
	return a - b;
}

int Span::findShortestSpan()
{
	int shortest = INT_MAX;
	for(std::vector<int>::iterator it = _span.begin(); it != _span.end() - 1; it++)
		if(shortest > findCurrentSpan(*it, *(it + 1)))
			shortest = findCurrentSpan(*it, *(it + 1));
	return shortest;
}

int Span::shortestSpan()
{
	if(_size > 1)
		return findShortestSpan();
	else
		invalidSpanException();
	return -1;
}

int Span::findLongestSpan()
{
	int longest = 0;
	for(std::vector<int>::iterator it = _span.begin(); it != _span.end() - 1; it++)
		if(longest < findCurrentSpan(*it, *(it + 1)))
			longest = findCurrentSpan(*it, *(it + 1));
	return longest;
}

int Span::longestSpan()
{
	if(_size > 1)
		return findLongestSpan();
	else
		invalidSpanException();
	return -1;
}

void Span::print()
{
	for(std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++)
		cout << *it << endl;
}

std::exception Span::maxSizeException()
{
	throw std::runtime_error("Error : Span is full");
}

std::exception Span::invalidSpanException()
{
	throw std::runtime_error("Error : Not enough numbers to have a span lenght");
}