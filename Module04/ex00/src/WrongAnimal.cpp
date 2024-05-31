#include "WrongCat.hpp"


WrongAnimal::WrongAnimal():type("")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	this->type = other.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makeSound function" << std::endl;
}