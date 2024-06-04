#include "AMateria.hpp"

AMateria::AMateria():type("null")
{
    std::cout << "AMateria Default canstructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
    std::cout << "AMateria Parameter canstructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria Copy canstructor called" << std::endl;
	this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria Operator overload called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

std::string const & AMateria::getType() const
{
	std::cout << "GetType AMateria Function called" << std::endl;
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "This is Materia " << target.getName() << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

