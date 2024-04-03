#include "Zombie.hpp"

int main()
{
	Zombie *z1;
	z1 = zombieHorde(7, "Frenk");
	for(int i = 0; i < 7; i++)
		z1->announce();
	delete[] z1;
	return (0);
}