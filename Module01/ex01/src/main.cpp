#include "Zombie.hpp"

int main()
{
	Zombie *z1;
	z1 = zombieHorde(7, "Frenk");
	Zombie *z2;
	z2 = zombieHorde(7, "Gag");
	for(int i = 0; i < 7; i++)
		z1->announce();
	for(int i = 0; i < 7; i++)
		z2->announce();
	delete[] z1;
	return (0);
}