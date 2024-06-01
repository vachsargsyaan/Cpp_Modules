#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}
Dog::Dog(const Dog &other):Animal(other)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->type = other.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain;
	*(this->brain) = *(other.brain);
	this->type = other.type;
}
Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
}
Dog& Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain;
	*(this->brain) = *(other.brain);
	this->type = other.type;
	return *this;	
}

void Dog::makeSound() const
{
	std::cout << "Gaf Gaf Gaf" << std::endl;
}