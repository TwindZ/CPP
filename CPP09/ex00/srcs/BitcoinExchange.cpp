#include "../inc/BitcoinExchange.hpp"

using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange()
{
	cout << "BitcoinExchange constructor call" << endl;
}

BitcoinExchange::BitcoinExchange(char *argv)
{
	_inputFileStream.open(argv);
	mapingInput();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy)
{
	cout << "BitcoinExchange copy constructor call" << endl;
	*this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const& copy)
{
	cout << "BitcoinExchange assignement call" << endl;
	if(this == &copy)
		return *this;
	_valueToConvert = copy._valueToConvert;
	return *this;

}

BitcoinExchange::~BitcoinExchange()
{
	cout << "BitcoinExchange destructor call" << endl;
}

float BitcoinExchange::tryToConvertBtc(string btcAmount)
{
	try
	{
		return std::stof(btcAmount);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : btc amount conversion fail" << endl;
		return -1;
	}
}

bool BitcoinExchange::btcAmountIsValid(string btcAmount)
{
	float btc = tryToConvertBtc(btcAmount);
	if(btc >= 0 && btc <= 1000)
		return true;
	std::cerr << "Error : btc value must be numeric between 0 and 1000" << endl;
	return false;
}

bool BitcoinExchange::dateIsValid(string date)
{
	//TODO parse the date;
	(void) date;
	return true;
}

void BitcoinExchange::mapingInput()
{
	string date;
	string btcAmount;
	std::getline(_inputFileStream, date, '\n'); //Burning fisrt line of the file.
	while(std::getline(_inputFileStream, date, '|'))
	{
		std::getline(_inputFileStream, btcAmount, '\n');
		if(dateIsValid(date) && btcAmountIsValid(btcAmount))
			_valueToConvert[date] = std::stof(btcAmount);
	}
}

void BitcoinExchange::print()
{
	typedef std::map<string, float>::iterator mapIterator;
	for(mapIterator it = _valueToConvert.begin(); it != _valueToConvert.end(); it++)
		cout << it->first << " : " << it->second << endl;
}