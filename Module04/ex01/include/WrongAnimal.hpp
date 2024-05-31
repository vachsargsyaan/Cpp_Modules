#pragma once

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		virtual ~WrongAnimal();
	public:
		 WrongAnimal& operator =(const WrongAnimal& other);
		void makeSound() const;

		 std::string getType() const;
		 void	setType(std::string type);
	protected:
		std::string type;
};
