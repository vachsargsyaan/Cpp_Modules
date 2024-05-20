#include "ClapTrap.hpp"

ClapTrap::ClapTrap():Name("NULL"), Hit(0), Energy(0), Attack(0)
{
    std::cout << "Default counstructor called" << std:: endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
    std::cout << "ClapTrap Parameter counstructor called" << std::endl;
    this->Name = name;
    this->Hit = 10;
    this->Energy = 10;
    this->Attack = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy counstructor called" << std::endl;
    this->Hit = other.Hit;
    this->Attack = other.Attack;
    this->Energy = other.Energy;
    this->Name = other.Name;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destrucktor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->Hit = other.Hit;
    this->Attack = other.Attack;
    this->Energy = other.Energy;
    this->Name = other.Name;
    return *this;
}

int	ClapTrap::getHit()
{
	return this->Hit;
}

int	ClapTrap::getEnergy()
{
	return this->Energy;
}
int	ClapTrap::getAttack()
{
	return this->Attack;	
}


std::string	ClapTrap::getName()
{
	return this->Name;
}


void ClapTrap::setAttack(unsigned int Attack)
{
    this->Attack = Attack;
}

void	ClapTrap::setHit(unsigned int Hit)
{
	this->Hit = Hit;
}

void	ClapTrap::setEnergy(unsigned int Energy)
{
	this->Energy = Energy;
}

void	ClapTrap::setName(std::string Name)
{
	this->Name = Name;
}

void ClapTrap::attack(const std::string& target)
{
    if (!this->Energy || !this->Hit)
		return ;
    std::cout << "ClapTrap " << this->Name << " attacks " << target <<  " causing ";
    std::cout << this->Attack << " points of damage!" << std::endl;
    -- this->Energy;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->Hit && this->Hit >= amount)
	{
		std::cout << this->Name << " Received damage " << amount << std::endl;
		this->Hit -= amount;
	}
	else
		std::cout << this->Name << " already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energy && this->Hit)
	{
		std::cout << this->Name << " Restores health " << amount << std::endl;
		this->Hit += amount;
		-- this->Energy;
	}
}

void ClapTrap::showInfo() const
{
	std::cout << "ClapTrap Name " << this->Name << std::endl;
	std::cout << "Healt : " << this->Hit << std::endl;
	std::cout << "Energy : " << this->Energy << std::endl;
	std::cout << "Attack : " << this->Attack << std::endl;
}
