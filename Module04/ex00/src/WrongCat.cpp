#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	this->type = other.type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Myau Myau Myau" << std::endl;
}
