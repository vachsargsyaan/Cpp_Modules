#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Default FragTrap constructor called" << std:: endl;
}

FragTrap::FragTrap(const std::string& name):ClapTrap(name)
{
	std::cout << "Operator FragTrap constructor called" << std::endl;
	this->_Hit_ = 100;
	this->_Energy_ = 100;
	this->_Attack_ = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "FragTrap copy counstructor called" << std::endl;
    this->_Hit_ = other._Hit_;
    this->_Attack_ = other._Attack_;
    this->_Energy_ = other._Energy_;
    this->Name = other.Name;
}

FragTrap::~FragTrap(){}

FragTrap&	FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_Hit_ = other._Hit_;
    this->_Attack_ = other._Attack_;
    this->_Energy_ = other._Energy_;
    this->Name = other.Name;
    return *this;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "high fives all form " << this->Name << " to all classes :)" <<std::endl;
}