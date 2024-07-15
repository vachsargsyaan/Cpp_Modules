#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
    AForm("unknown", PresidentialPardonForm::MAX_REQUIRED_SIGN,PresidentialPardonForm::MAX_REQUIRED_EXEC),target("unknown")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& tg):
     AForm(tg, PresidentialPardonForm::MAX_REQUIRED_SIGN,PresidentialPardonForm::MAX_REQUIRED_EXEC),target(tg)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
    AForm(other.GetName(), other.GetGradeSign(), other.GetgradeExec())
{
    this->target = other.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }

    return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->checkExec(executor);
    this->checkSign();

    std::cout << this->GetName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}