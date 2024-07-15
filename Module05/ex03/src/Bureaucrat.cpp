#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("no Name"), grade(150)
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name)
{
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name)
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

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const {
    return (this->name);
}

void Bureaucrat::incrementGrade()
{
    int newGrade = this->getGrade() - 1;
    this->setGrade(newGrade);
}

void Bureaucrat::decrementGrade(void)
{
    int newGrade = this->getGrade() + 1;
    this->setGrade(newGrade);
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj) {
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return (os);
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return (this->errMsg.c_str());
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw() {
    return (this->errMsg.c_str());
}

void Bureaucrat::signAForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.GetName() << " form" << std::endl;
    }
    catch(const std::exception& ex)
    {
        std::cout << this->getName() << " couldn’t sign " << form.GetName() << " form because " << ex.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.executeForm(*this);
        std::cout << this->getName() << " executed " << form.GetName() << " form" << std::endl;
    } catch (const std::exception& ex) {
        std::cout << this->getName() << " couldn’t execute " << form.GetName() << " form because " << ex.what() << std::endl;
    }
}
