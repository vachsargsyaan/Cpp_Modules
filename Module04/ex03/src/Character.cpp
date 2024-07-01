#include "Character.hpp"
#include "AMateria.hpp"

Character::Character():name("null")
{
	std::cout << "Character Default constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		this->slot[i] = NULL;
}

Character::Character(const std::string name)
{
	std::cout << "Character Parameter constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; ++i)
		this->slot[i] = NULL;
}

Character::Character(const Character &other)
{
	std::cout << "Character Copy constructor called" << std::endl;
	this->name = other.name;
	for (int i = 0; i < 4; ++i)
	{
		delete this->slot[i];
		this->slot[i] = other.slot[i]->clone();
	}
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		delete this->slot[i];
}

Character& Character::operator =(const Character &other)
{
	std::cout << "Ice Operator overload called" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name;
	for (int i = 0; i < 4; ++i)
	{
		delete this->slot[i];
		this->slot[i] = other.slot[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; ++i)
        	if (this->slot[i] == m)
            	return ;
		for (int i = 0; i < 4; i++)
		{
			if (!this->slot[i])
			{
				this->slot[i] = m;
				return ;
			}	
		}
	}
	std::cout << "Einventory Is Full." << std::endl;
}
void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && this->slot[idx])
	{
		delete this->slot[idx];
		this->slot[idx] = NULL;
		return ;
	}
	std::cout << "Materia Doesn't Exist." << std::endl;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->slot[idx])
		this->slot[idx]->use(target);
	else
		std::cout << "Materia Doesn't Exist." << std::endl;
}