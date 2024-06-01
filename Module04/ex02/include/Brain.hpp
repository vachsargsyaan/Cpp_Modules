#pragma once

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
	public:
	 	Brain& operator =(const Brain& other);
		void	setIdea(std::string &idea, const int Index);
		std::string getIdea(const int Index);
	private:
		std::string idea[100];
};