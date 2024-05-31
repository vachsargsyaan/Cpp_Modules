#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
	public:
		 Animal& operator =(const Animal& other);
		 virtual void makeSound() const;

		 std::string getType() const;
		 void	setType(std::string type);
	protected:
		std::string type;
};
