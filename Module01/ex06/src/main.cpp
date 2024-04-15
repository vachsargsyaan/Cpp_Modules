#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Not coorect command\n";
		return (0);
	}

	Harl obj;
	obj.complain(argv[1]);
	return (0);
}