#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "../inc/BitcoinExchange.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Usage : ./btc <InputFile>" << endl;
		exit (EXIT_FAILURE);
	}
	BitcoinExchange exchange(argv[1]);
	
	exchange.print();
	
	
	
	
	
	
	
	// std::map<string, float> valueToCovert;
	// std::ifstream	inputFile(argv[1]);
	// string date;
	// string exchangeRate;
	// std::getline(inputFile, date, '\n');
	// while(std::getline(inputFile, date, '|'))
	// {
	// 	std::getline(inputFile, exchangeRate, '\n');
	// 	[date] = std::stof(exchangeRate);
	// 	cout << date << " : "<< exchangeRate << endl;
	// }	
}