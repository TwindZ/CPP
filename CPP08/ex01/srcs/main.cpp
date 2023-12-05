#include <iostream>
#include <vector>
#include <list>
#include "../inc/Span.hpp"

using std::string;
using std::cout;
using std::endl;

int main()
{
	size_t spanSize = 10;
	Span span1(spanSize);
	Span span2(1);
	
	srand(time(0));
	for(size_t i = 0; i < spanSize; ++i)
	{
		span1.addNumber(rand() % 500);
	}	

	cout << endl << "############################################################"<< endl;
	cout << "SPAN1 TEST"<< endl;
	span1.print();
	cout << "Sortest span1 : " << span1.shortestSpan() << endl;
	cout << "Longest span1 : " << span1.longestSpan() << endl;
	
	cout << endl << "############################################################"<< endl;
	cout << "TEST SPAN2 (one number) EXCEPTION"<< endl;
	span2.addNumber(3);
	try
	{
		span2.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		span2.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	cout << endl << "############################################################"<< endl;
	cout << "TEST OPERATOR ="<< endl;
	span2.print();
	span2 = span1;
	span2.print();
	cout << "Sortest span2 : " << span2.shortestSpan() << endl;
	cout << "Longest span2 : " << span2.longestSpan() << endl;

	cout << endl << "############################################################"<< endl;
	cout << "TEST COPY CONSTRUCTOR" << endl;
	Span span3(span2);
	span3.print();

	cout << endl << "############################################################"<< endl;
	cout << "TEST FROM PDF" << endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	cout << endl << "############################################################"<< endl;
	cout << "TEST ADDNUMBERSARRAY" << endl;
	int numbersArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Span span4(11);
	span4.addNumber(0);
	span4.addNumbersArray(numbersArray, 5);
	try
	{
		span4.addNumbersArray(numbersArray, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	span4.print();
	cout << "Longest span4 : " << span4.longestSpan() << endl;

	
}