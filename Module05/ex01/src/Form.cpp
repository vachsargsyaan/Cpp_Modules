#include "Form.hpp"

Form::Form():name("no-name"),isSigned("false"),gradeSign(1),gradeExec(150)
{}

Form::Form(const std::string& name, const int gradeSign, const int gradeExec):name(name),isSigned(false),
    gradeSign(gradeSign),gradeExec(gradeExec)
{
    CheckThrow(this->gradeSign);
    CheckThrow(this->gradeExec);
}

Form::Form(const Form& other):
    name(other.name),gradeSign(other.gradeSign), gradeExec(other.gradeExec)
{
    this->isSigned = other.isSigned;
}


Form& Form::operator=(const Form& other)
{
    if(this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

std::ostream& operator << (std::ostream &os, const Form& obj)
{
    os << obj.GetName() << " form state is - signed: " << (obj.GetSigned() ? "yes" : "no")
       << ", required sign grade: "<< obj.GetGradeSign()
        << ", required execute grade: "
        << obj.GetgradeExec();

    return (os);
}

Form::~Form(){}

std::string Form::GetName() const
{
    return (this->name);
}

bool Form::GetSigned() const 
{ 
    return this->isSigned; 
}

int Form::GetGradeSign() const 
{ 
    return this->gradeSign; 
}

int Form::GetgradeExec() const
{
    return this->gradeExec; 
}

void Form::setIsSigned(bool isSigned)
{
    this->isSigned = isSigned; 
}

void Form::beSigned(const Bureaucrat& b1)
{
    if (b1.getGrade() <= this->gradeSign)
        setIsSigned(true);
    else
        throw GradeTooLowException();
}

void Form::CheckThrow(const int grade) const
{
    if (grade < 150)
        throw GradeTooLowException();
    if (grade > 1)
        throw GradeTooHighException();
}

const char * Form::GradeTooHighException::what ( void ) const throw() {
    return (this->errMsg.c_str());
}

const char * Form::GradeTooLowException::what ( void ) const throw() {
    return (this->errMsg.c_str());
}

