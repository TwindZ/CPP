#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <exception>
# include <stdexcept>
# include <map>

using std::string;
using std::cout;
using std::endl;
using std::cerr;

class BitcoinExchange
{
	private:

		std::map<string, double> _csvData;
		std::ifstream _inputFileStream;
		std::ifstream _csvFileStream;

		void tryOpenFile(char *argv);
		void openCsv();
		void mapingCsv();
		void openInput(string file);
		void mapingInput();
		bool isDecimalValueFormatValid(string const& value)const;
		bool isValueValid(string const& value)const;
		bool isLeapYear(int const& year)const;
		bool isDateValid(string const& date)const;
		bool isValidValueRange(string const& value)const;
		void calculateOutput(string const& date, string const& value)const;

		std::exception failToOpenFileException();

	public:
		
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& Copy);
		BitcoinExchange & operator=(BitcoinExchange const& Copy);
		~BitcoinExchange();
		void exchanger(char *argv);

		void printCsv();
};

#endif