#include "Zombie.hpp"

Zombie::Zombie(std::string& _zombi_name)
{
	std::cout << "Zobmie created\n";
	this->_zombi_name = _zombi_name;
}

Zombie::~Zombie()
{
	std::cout << "Destructor callde " << "\n";
	std::cout << this->_zombi_name << " destroyed\n";
}

void	Zombie::announce(void)
{
	std::cout << this->_zombi_name << ": BraiiiiiiinnnzzzZ...\n";
}