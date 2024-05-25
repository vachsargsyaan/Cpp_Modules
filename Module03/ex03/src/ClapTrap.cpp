#include "ClapTrap.hpp"

ClapTrap::ClapTrap():Name("NULL"), _Hit_(0), _Energy_(0), _Attack_(0)
{
    std::cout << "ClapTrap Default counstructor called" << std:: endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
    std::cout << "ClapTrap  Parameter counstructor called" << std::endl;
    this->Name = name;
    this->_Hit_ = 10;
    this->_Energy_ = 10;
    this->_Attack_ = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy counstructor called" << std::endl;
    this->_Hit_ = other._Hit_;
    this->_Attack_ = other._Attack_;
    this->_Energy_ = other._Energy_;
    this->Name = other.Name;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destrucktor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_Hit_ = other._Hit_;
    this->_Attack_ = other._Attack_;
    this->_Energy_ = other._Energy_;
    this->Name = other.Name;
    return *this;
}

int	ClapTrap::getHit()
{
	return this->_Hit_;
}

int	ClapTrap::getEnergy()
{
	return this->_Energy_;
}
int	ClapTrap::getAttack()
{
	return this->_Attack_;	
}


std::string	ClapTrap::getName()
{
	return this->Name;
}


void ClapTrap::setAttack(unsigned int Attack)
{
    this->_Attack_ = Attack;
}

void	ClapTrap::setHit(unsigned int Hit)
{
	this->_Hit_ = Hit;
}

void	ClapTrap::setEnergy(unsigned int Energy)
{
	this->_Energy_ = Energy;
}

void	ClapTrap::setName(std::string Name)
{
	this->Name = Name;
}

void ClapTrap::attack(const std::string& target)
{
    if (!this->_Energy_ || !this->_Hit_)
		return ;
    std::cout << "ClapTrap " << this->Name << " attacks " << target <<  " causing ";
    std::cout << this->_Attack_ << " points of damage!" << std::endl;
    -- this->_Energy_;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_Hit_ && this->_Hit_ >= amount)
	{
		std::cout << this->Name << " Received damage " << amount << std::endl;
		this->_Hit_ -= amount;
	}
	else
		std::cout << this->Name << " already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Energy_ && this->_Hit_)
	{
		std::cout << this->Name << " Restores health " << amount << std::endl;
		this->_Hit_ += amount;
		-- this->_Energy_;
	}
}

void ClapTrap::showInfo() const
{
	std::cout << "ClapTrap Name " << this->Name << std::endl;
	std::cout << "Healt : " << this->_Hit_ << std::endl;
	std::cout << "Energy : " << this->_Energy_ << std::endl;
	std::cout << "Attack : " << this->_Attack_ << std::endl;
}
