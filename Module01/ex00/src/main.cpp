#include <Zombie.hpp>

int main()
{
	Zombie *Z1;
	Z1 = newZombie("Davo");
	Z1->announce();
	randomChump("Ando");
	delete Z1;
}