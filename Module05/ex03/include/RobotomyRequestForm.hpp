#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& tg);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
    public:
        RobotomyRequestForm& operator= (const RobotomyRequestForm& other);
    public:
        static const int MAX_REQUIRED_SIGN = 72;
        static const int MAX_REQUIRED_EXEC = 45;
    public:
        void execute(Bureaucrat const & executor) const;
    private:
        std::string target;
};
