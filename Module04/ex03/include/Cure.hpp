#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const std::string &type);
	Cure(const Cure &other);
	Cure& operator =(const Cure &other);
	~Cure();
	AMateria* clone() const;
	void use(ICharacter& target);
};