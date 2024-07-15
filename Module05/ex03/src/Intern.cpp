#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern&){}

Intern& Intern::operator=(const Intern&)
{
    return (*this);
}

Intern::~Intern(){}

AForm* Intern::makeForm(std::string form, std::string target)
{
    const int size = 3;

    std::string forms[size] = {"Shrubbery request", "robotomy request", "Presidential request"};
    AForm *jobs[size] = {new ShrubberyCreationForm(target), new RobotomyRequestForm (target), new PresidentialPardonForm(target)};
    AForm *res = NULL;

    for (int i = 0; i < size; i++)
    {
        if (forms[i] == form)
         res = jobs[i];
        else
            delete jobs[i];
    }
    if (!res)
        throw std::runtime_error("There is no such position!\n");
    else
        return (res);
}