#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->idea[i] = other.idea[i];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->idea[i] = other.idea[i];
	return *this;
}

void	Brain::setIdea(std::string &idea, const int Index)
{
	return this->idea[Index] = idea;
}

std::string Brain::getIdea(const int Index)
{
	return this->idea[Index];
}