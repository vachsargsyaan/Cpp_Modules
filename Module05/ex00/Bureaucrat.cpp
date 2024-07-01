#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("no Name"),grade(150)
{}

Bureaucrat::Bureaucrat(const std::string& name, int& grade):name(name)
{
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name)
{
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	this->grade = other.grade;
	return (*this);
}