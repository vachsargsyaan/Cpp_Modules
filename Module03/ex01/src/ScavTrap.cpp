#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string &_name_):ClapTrap(_name_)
{
	std::cout << "Operator ScavTrap constructor called" << std::endl;
	this->_Hit_ = 100;
	this->_Attack_ = 50;
	this->_Energy_ = 20;
}

ScavTrap::~ScavTrap()
{}

ScavTrap&  ScavTrap::operator=(const ScavTrap &other)
{
        std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_Hit_ = other._Hit_;
    this->_Attack_ = other._Attack_;
    this->_Energy_ = other._Energy_;
    this->Name = other.Name;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (!this->_Energy_ || !this->_Hit_)
		return ;
    std::cout << "ScavTrap " << this->Name << " attacks " << target <<  " causing ";
    std::cout << this->_Attack_ << " points of damage!" << std::endl;
    -- this->_Energy_;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in gate guard mode." << std::endl;	
}