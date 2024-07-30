#include "Base.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	{
		Base *ptr;
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		std::cout << std::endl;
		delete ptr;
	}
	{
		Base *ptr;
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		std::cout << std::endl;
		delete ptr;
	}
	{
		Base *ptr;
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	return 0;
}