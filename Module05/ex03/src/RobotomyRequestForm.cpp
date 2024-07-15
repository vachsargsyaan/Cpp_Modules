#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
    AForm("unknown", RobotomyRequestForm::MAX_REQUIRED_SIGN,RobotomyRequestForm::MAX_REQUIRED_EXEC),target("unknown")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& tg):
     AForm(tg, RobotomyRequestForm::MAX_REQUIRED_SIGN,RobotomyRequestForm::MAX_REQUIRED_EXEC),target(tg)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
    AForm(other.GetName(), other.GetGradeSign(), other.GetgradeExec())
{
    this->target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }

    return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->checkExec(executor);
    this->checkSign();

    std::srand(time(NULL));

    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully."<<std::endl;
    else
         std::cout << this->target << " robotomy failed."<<std::endl;
}