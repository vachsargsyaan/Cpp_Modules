#include "AForm.hpp"

AForm::AForm():name("unknown"),isSigned(false),
    gradeSign(1),gradeExec(150){}

AForm:: AForm(const std::string& name, const int gradeSign, const int gradeExec):
    name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    CheckThrow(this->gradeSign);
    CheckThrow(this->gradeExec);
}

AForm::AForm(const AForm& other):
    name(other.name),gradeSign(other.gradeSign), gradeExec(other.gradeExec)
{
    this->isSigned = other.isSigned;
}

AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

AForm::~AForm(){}

std::string AForm::GetName() const
{
    return this->name;
}

bool AForm::GetSigned() const
{
    return this->isSigned;
}

int AForm::GetGradeSign() const
{
    return this->gradeSign;
}

int AForm::GetgradeExec() const
{
    return this->gradeExec;
}

void AForm::setIsSigned(bool isSigned){
    this->isSigned = isSigned;
}

void AForm::beSigned(const Bureaucrat& b1)
{
    if (b1.getGrade() <= this->gradeSign)
         setIsSigned(true);
    else
        throw GradeTooLowException();
}

void AForm::CheckThrow(const int grade) const
{
    if (grade < 150)
        throw GradeTooLowException();
    if (grade > 1)
        throw GradeTooHighException();
}


void AForm::checkExec(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->gradeExec)
        throw GradeTooLowException();
}

void AForm::checkSign() const
{
    if (!this->GetSigned())
        throw std::runtime_error("Form cannot be signed\n"); 
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!\n");
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!\n");
}


void AForm::executeForm(Bureaucrat const & target) const
{
    this->execute(target);
}

std::ostream& operator << (std::ostream &os, const AForm& obj)
{
    os << obj.GetName() << " form state is - signed: " << (obj.GetSigned() ? "yes" : "no")
       << ", required sign grade: "<< obj.GetGradeSign()
        << ", required execute grade: "
        << obj.GetgradeExec();

    return (os);
}