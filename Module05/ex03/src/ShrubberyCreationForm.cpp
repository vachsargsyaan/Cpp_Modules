#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
    AForm("unknown", ShrubberyCreationForm::MAX_REQUIRED_SIGN,ShrubberyCreationForm::MAX_REQUIRED_EXEC),target("unknown")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& tg):
     AForm(tg, ShrubberyCreationForm::MAX_REQUIRED_SIGN,ShrubberyCreationForm::MAX_REQUIRED_EXEC),target(tg)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
    AForm(other.GetName(), other.GetGradeSign(), other.GetgradeExec())
{
    this->target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }

    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkExec(executor);
    this->checkSign();

    std::ofstream drawFile;
    
    drawFile.open((this->GetName() + "_shrubbery").c_str(),  std::ios::trunc);

     if (!drawFile)
        throw std::runtime_error("Cannot open file\n");

    drawFile << "                  v .   ._, |_  .," << std::endl;
    drawFile << "           `-._\\/  .  \\ /    |/_" << std::endl;
    drawFile << "               \\  _\\, y | \\//" << std::endl;
    drawFile << "         _\\_.___\\, \\/ -.\\||" << std::endl;
    drawFile << "           `7-,--.`._||  / / ," << std::endl;
    drawFile << "           /'     `-. `./ / |/_.'" << std::endl;
    drawFile << "                     |    |//" << std::endl;
    drawFile << "                     |_    /" << std::endl;
    drawFile << "                     |-   |" << std::endl;
    drawFile << "                     |   =|" << std::endl;
    drawFile << "                     |    |" << std::endl;
    drawFile << "--------------------/ ,  . \\--------._" << std::endl;

    drawFile.close();
}