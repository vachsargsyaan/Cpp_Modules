#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	if (ac != 2)
	{
		std::cerr << _ERROR_ARGUMENTS_ << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange::dbData("data.csv");
		BitcoinExchange::validInput(av[1]);
	}
	catch(const mstd::ExpHandler& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}