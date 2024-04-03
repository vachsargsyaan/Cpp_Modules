#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
	public:
		Zombie(std::string&  _zombi_name);
		~Zombie();
		void announce( void );
	private:
		std::string	_zombi_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
#endif