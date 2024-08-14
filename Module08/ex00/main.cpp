#include "easyfinde.hpp"

int main()
{
	std::vector<int> arr;
	for (int i = 0; i < 10; ++ i)
		arr.push_back(i);
	try
	{
		std::cout << easyfinde(arr, 5) << std::endl;
		std::cout << easyfinde(arr, 1) << std::endl;
		std::cout << easyfinde(arr, 100) << std::endl;
		std::cout << easyfinde(arr, 200) << std::endl;
		std::cout << easyfinde(arr, 9) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}