#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << _ERROR_ARGUMENTS_ << std::endl;
		return 1;
	}
	try
	{
		RPN::Reverse_Polish_Notation(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}