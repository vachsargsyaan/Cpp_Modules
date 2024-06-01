#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();
	public:
		WrongCat& operator =(const WrongCat& other);
		void makeSound() const;
};