#include "ICharacter.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default constructop called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->slot[i] = NULL;
}


MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource Copy constructop called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		delete this->slot[i];
		this->slot[i] = other.slot[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructop called" << std::endl;
	for (int i = 0; i < 4; ++i)
		delete this->slot[i];
}
MateriaSource& MateriaSource::operator =(const MateriaSource &other)
{
	std::cout << "Ice Operator overload called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; ++i)
	{
		delete this->slot[i];
		this->slot[i] = other.slot[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->slot[i] == materia)
			return ;
		if (!this->slot[i])
		{
			this->slot[i] = materia;
			std::cout << "MateriaSource learned." << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource can't learn." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->slot[i] && this->slot[i]->getType() == type)
			return this->slot[i]->clone();
	}
	return NULL;
}