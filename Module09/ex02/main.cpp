#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		PmergeMe::valid_args(ac, av);
		PmergeMe::_PmergeMe_();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}