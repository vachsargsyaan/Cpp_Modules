#include "HumanA.hpp"

HumanA::HumanA(const std::string& _name, const Weapon& _wp) : wp(_wp)
{
	this->_name = _name;
	this->wp = _wp;
}

HumanA::~HumanA(){}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their "<< wp.getType()<< "\n";
}

void HumanA::setWeapon(const Weapon& _wp) {
    this->wp = _wp;
}