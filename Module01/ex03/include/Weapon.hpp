#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon(const std::string& attribute_type);
		~Weapon();
		std::string& getType();
		void		setType(std::string type);
	private:
		std::string attribute_type;
};

#endif