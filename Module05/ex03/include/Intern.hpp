#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern {

    public:
        Intern();
        Intern( const Intern & );
        ~Intern();

    public:
        Intern & operator=( const Intern & );

    public:
        AForm * makeForm( std::string, std::string target);
};