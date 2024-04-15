#include "Zombie.hpp"

Zombie::Zombie(const std::string& _name)
{
	this->_name = _name;
}

Zombie::Zombie(){};

Zombie::~Zombie(){};

void	Zombie::announce(void)
{
	std::cout  << _name << ": BraiiiiiiinnnzzzZ...\n";
}