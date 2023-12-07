#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <map>

using std::string;

class BitcoinExchange
{
	private:

		std::map<string, float> _valueToConvert;
		std::ifstream _inputFileStream;
		BitcoinExchange();

		float tryToConvertBtc(string btcAmount);
		bool btcAmountIsValid(string btcAmount);
		bool dateIsValid(string date);
		void mapingInput();

	public:
		
		BitcoinExchange(char *argv);
		BitcoinExchange(BitcoinExchange const& Copy);
		BitcoinExchange & operator=(BitcoinExchange const& Copy);
		~BitcoinExchange();

		void print();
};

#endif