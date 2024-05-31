#pragma once

#include "Cat.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
	public:
		Dog& operator =(const Dog& other);
		void makeSound() const;
	private:
		Brain *brain;
};