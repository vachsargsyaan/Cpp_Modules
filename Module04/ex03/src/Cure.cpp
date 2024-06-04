#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(const std::string &type):AMateria(type)
{
	std::cout << "Cure Parameter constructor called" << std::endl;
}

Cure::Cure(const Cure &other):AMateria(other)
{
	std::cout << "Cure Copy constructor called" << std::endl;
}
Cure::~Cure()
{	
	std::cout << "Cure Destructor called" << std::endl;
}
Cure& Cure::operator =(const Cure &other)
{
	std::cout << "Cure Operator overload called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}
AMateria* Cure::clone() const
{
	return (new Cure(*this));
}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *"<< " *" << std::endl;
}