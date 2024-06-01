#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
	public:
		Cat& operator =(const Cat& other);
		void makeSound() const;
	private:
		Brain *brain;
};