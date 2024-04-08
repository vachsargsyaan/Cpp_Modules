#include "HumanA.hpp"

Weapon::Weapon(const std::string& attribute_type):attribute_type(attribute_type)
{}

Weapon::~Weapon(){}

std::string& Weapon::getType()
{
	return this->attribute_type;
}

void	Weapon::setType(std::string type)
{
	this->attribute_type = type;
}