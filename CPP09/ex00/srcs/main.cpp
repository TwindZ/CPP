#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Usage : ./btc <InputFile>" << std::endl;
		exit (EXIT_FAILURE);
	}
	BitcoinExchange exchange;
	exchange.exchanger(argv[1]);
}