#include "Dog.hpp"

Cat::Cat()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(const Cat &other):Animal(other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->type = other.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain;
	*(this->brain) = *(other.brain);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Operator Assignment Cat called" << std::endl;
	if (this == &other)
		return *this;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain;
	this->type = other.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Myau Myau Myau" << std::endl;
}
