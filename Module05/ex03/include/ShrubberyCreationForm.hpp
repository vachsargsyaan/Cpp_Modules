#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& tg);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
    public:
        ShrubberyCreationForm& operator= (const ShrubberyCreationForm& other);
    public:
        static const int MAX_REQUIRED_SIGN = 145;
        static const int MAX_REQUIRED_EXEC = 137;
    public:
        void execute(Bureaucrat const & executor) const;
    private:
        std::string target;
};