#include "Zombie.hpp"

Zombie::Zombie(std::string& _name)
{
	this->_name = _name;
}

Zombie::Zombie(){};

Zombie::~Zombie(){};

void	Zombie::announce(void)
{
	std::cout << ": BraiiiiiiinnnzzzZ...\n";
}