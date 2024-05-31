#include "Dog.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->type = other.type;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Myau Myau Myau" << std::endl;
}
