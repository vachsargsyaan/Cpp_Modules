#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "HumanB.HPP"


class HumanA
{
	public:
		HumanA(const std::string& _name, const Weapon& _wp);
		~HumanA();
		void	attack();
		void	setWeapon(const Weapon& _wp);
	private:
		std::string _name;
		Weapon wp;
};

#endif