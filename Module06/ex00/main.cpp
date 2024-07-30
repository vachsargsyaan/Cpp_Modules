#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return 0;
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(ScalarConverter::Handel &ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	return 0;
}