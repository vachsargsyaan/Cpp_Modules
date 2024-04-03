#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie *tmp;
	tmp = new Zombie(name);
	return tmp;
}