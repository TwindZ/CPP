#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange():
_csvData(), _inputFileStream(), _csvFileStream()
{
	cout << "BitcoinExchange constructor call" << endl;
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
	_csvData = copy._csvData;
	return *this;

}

BitcoinExchange::~BitcoinExchange()
{
	cout << "BitcoinExchange destructor call" << endl;
}

void BitcoinExchange::exchanger(char *argv)
{
	try
	{
		openCsv();
		openInput(argv);
		mapingCsv();
		mapingInput();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void BitcoinExchange::openCsv()
{
		_csvFileStream.open("data.cs");
		if (!_csvFileStream.is_open())
			failToOpenFileException();
}

void BitcoinExchange::mapingCsv()
{
	string line, rate, date;
	const string firstLine("date,exchange_rate");
	std::getline(_csvFileStream, line, '\n');
	if(line != firstLine)
		std::cerr << "Error : Bad fisrt line of the csv file" << endl;
	while(std::getline(_csvFileStream, date, ','))
	{
		std::getline(_csvFileStream, rate);
		if(!isDecimalValueFormatValid(rate) || std::stod(rate) < 0)
			cerr << "Error: Invalid decimal number format: " << date << endl;
		else if(!isDateValid(date) || !isValueValid(rate))
			cerr << "Error: Invalid csv date or value  (YYYY-MM-DD | Value) : " << date << endl;
		else
			_csvData[date] = std::stod(rate);
	}
}

void BitcoinExchange::openInput(string file)
{
		_inputFileStream.open(file);
		if (!_inputFileStream.is_open())
			failToOpenFileException();
}

void BitcoinExchange::mapingInput()
{
	string line;
	string value;
	string date;
	const string firstLine("date | value");
	std::getline(_inputFileStream, line, '\n');
	if(line != firstLine)
		std::cerr << "Error : Bad fisrt line of the input file" << endl;
	while(std::getline(_inputFileStream, line))
	{
		std::stringstream ss(line);
		char separator;
		if(!(ss >> date >> separator >> value) || separator != '|')
			cerr << "Error: Missing Date or Value information : " << date << endl;
		else if(!isDecimalValueFormatValid(value))
			cerr << "Error: Invalid decimal number format: " << date << endl;
		else if(!isDateValid(date) || !isValueValid(value))
			cerr << "Error: Invalid input date or value  (YYYY-MM-DD | Value) : " << date << endl;
		else if(isValidValueRange(value) == false)
			cerr << "Error: Value must be between 0 and 1000 : " << date << endl;
		else if(isValidValueRange(value) == true)
			calculateOutput(date, value);
	}
}

bool	BitcoinExchange::isDecimalValueFormatValid(string const& value)const
{
	size_t dotPos = value.find('.');
	if (dotPos != string::npos)
	{
		if(!std::isdigit(value.c_str()[dotPos + 1]))
			return false;
		size_t nextDotPos = value.find('.', dotPos + 1);
		if (nextDotPos != string::npos)
			return false;
	}
	return true;
}

bool BitcoinExchange::isValueValid(string const& value)const
{
	try
	{
		std::stod(value);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error : value conversion fail" << endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int const& year)const
{
	return((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool	BitcoinExchange::isDateValid(string const& date)const
{
	if (date.length() != 10)
		return false;
	int year, month, day;
	char separator1, separator2;
	std::istringstream ss(date);
	ss >> year >> separator1 >> month >> separator2 >> day;
	if (ss.fail() || separator1 != '-' || separator2 != '-' || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	bool leap_year = isLeapYear(year);
	if ((month == 2 && (leap_year ? day > 29 : day > 28)) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
		return false;
	return true;
}

bool BitcoinExchange::isValidValueRange(string const& value)const
{
	return std::stod(value) >= 0 && std::stod(value) <= 1000;
}

void	BitcoinExchange::calculateOutput(string const& date, string const& value)const
{
	std::map<string, double>::const_iterator it = _csvData.find(date);
	if (it == _csvData.end())
	{
		it = _csvData.lower_bound(date);
		it--;
	}
	double rate = it->second;
	string rateDate = it->first;
	double multiplication = std::stod(value) * rate;
	cout << date << " : "<< value << " * " << rate << "(" ;
	cout << rateDate << ") = " << multiplication << endl;
}

std::exception BitcoinExchange::failToOpenFileException()
{
	throw std::runtime_error("Fatal : Fail to open file exception.");
}

void BitcoinExchange::printCsv()
{
	typedef std::map<string, double>::iterator mapIterator;
	for(mapIterator it = _csvData.begin(); it != _csvData.end(); it++)
		cout << it->first << " : " << it->second << endl;
}