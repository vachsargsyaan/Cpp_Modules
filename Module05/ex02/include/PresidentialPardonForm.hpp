#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
    	PresidentialPardonForm();
    	PresidentialPardonForm(const std::string& tg);
    	PresidentialPardonForm(const PresidentialPardonForm& other);
    	~PresidentialPardonForm();
	public:
    	PresidentialPardonForm& operator= (const PresidentialPardonForm& other);
	public:
		void execute(Bureaucrat const & executor) const;
};