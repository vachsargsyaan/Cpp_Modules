#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():_name_("nil")
{
	std::cout << "DiamondTrap Default counstructor called ..." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name):ClapTrap(),_name_(name)
{
	std::cout << "DiamondTrap Parameter counstructor called ..." << std::endl;
	this->_Hit_ = 100;
	this->_Energy_ = 50;
	this->_Attack_ = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):ClapTrap(other),FragTrap(other),ScavTrap(other)
{
	std::cout << "DiamondTrap copy counstructor called ..." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destrucktor ..." << std::endl;
}

DiamondTrap& DiamondTrap::operator =(const DiamondTrap &other)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_name_ = other._name_;
	this->_Hit_ = other._Hit_;
	this->_Energy_ = other._Energy_;
	this->_Attack_ = other._Attack_;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name: " << this->_name_ << std::endl;
}