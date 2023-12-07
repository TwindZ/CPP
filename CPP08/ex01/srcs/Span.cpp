#include "../inc/Span.hpp"

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
	if(this == &copy)
		return *this;
	_span = copy._span;
	_size = copy._size;
	return *this;
}

Span::~Span()
{
	cout << "Span destructor call" << endl;
}

uint32_t Span::findCurrentSpan(int const& a, int const& b)const
{
	if(a - b < 0)
		return (a - b) * -1;
	return a - b;
}

uint32_t Span::findShortestSpan()const
{
	uint32_t shortest = longestSpan();
	std::vector<int> copy(_span);
	std::sort(copy.begin(), copy.end());
	for(std::vector<int>::iterator it = copy.begin(); it != copy.end() - 1; it++)
		if(shortest > findCurrentSpan(*it, *(it + 1)))
			shortest = findCurrentSpan(*it, *(it + 1));
	return shortest;
}

uint32_t Span::shortestSpan()const
{
	if(_size > 1)
		return findShortestSpan();
	else
		invalidSpanException();
	return -1;
}

uint32_t Span::longestSpan()const
{
	if(_size < 2)
		invalidSpanException();
	return *std::max_element(_span.begin(), _span.end()) 
		- *std::min_element(_span.begin(), _span.end());
}

void Span::print()
{
	for(std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++)
		cout << *it << endl;
}

void Span::addNumber(int number)
{
	if(_span.size() < _size)
		_span.push_back(number);
	else
		maxSizeException();
}

void Span::addNumber(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd)
{
	std::ptrdiff_t range = std::distance(itBegin, itEnd);
	if(static_cast<size_t>(range) + _span.size() > _size)
		maxSizeException();
	_span.insert(_span.end(), itBegin, itEnd);
}

std::exception Span::maxSizeException()const
{
	throw std::runtime_error("Error : Not enough space in span");
}

std::exception Span::invalidSpanException()const
{
	throw std::runtime_error("Error : Not enough numbers to have a span lenght");
}