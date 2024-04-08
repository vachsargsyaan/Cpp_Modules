#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string& _name, const Weapon& wp);
		HumanB(const std::string& _name);
		~HumanB();
		void	attack();
		void	setWeapon(const Weapon& _wp);
	private:
		std::string _name;
		Weapon wp;
};

#endif