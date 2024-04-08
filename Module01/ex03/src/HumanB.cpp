#include "HumanA.hpp"


HumanB::HumanB(const std::string& _name, const Weapon& _wp) : wp(_wp)
{
	this->_name = _name;
	this->wp = _wp;
}
HumanB::HumanB(const std::string& _name):_name(_name), wp("fists")
{}

HumanB::~HumanB(){}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their "<< wp.getType()<< "\n";
}
void HumanB::setWeapon(const Weapon& _wp) {
    this->wp = _wp;
}