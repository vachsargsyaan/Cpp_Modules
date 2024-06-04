#pragma once

#include <iostream>
#include "AMateria.hpp"


class Ice : public AMateria
{
public:
	Ice();
	Ice(const std::string &type);
	Ice(const Ice &other);
	Ice& operator =(const Ice &other);
	~Ice();
	AMateria* clone() const;
	void use(ICharacter& target);
};
