#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const std::string& name, const int gradeSign, const int gradeExec);
        Form(const Form& other);
        ~Form();
    public:
        Form& operator=(const Form& other);
    public:
        std::string GetName() const;
        bool        GetSigned() const;
        int         GetGradeSign() const;
        int         GetgradeExec() const;
    public:
        void        setIsSigned(bool isSigned);
    public:
        	class GradeTooLowException : public std::exception
            {
                private:
                    std::string errMsg;
                public:
                    GradeTooLowException() : errMsg("Grade is too low!\n") {}
                    ~GradeTooLowException() throw() {};
                public:
                    const char * what() const throw();
            };
		  class GradeTooHighException : public std::exception
          {
            private:
                std::string errMsg;
            public:
                GradeTooHighException() : errMsg("Grade is too high!\n") {}
                ~GradeTooHighException() throw() {};
            public:
                const char * what() const throw();
        };
    public:
        void    beSigned(const Bureaucrat& b1);
         void   CheckThrow(const int grade) const;
    private:
        std::string const name;
        bool        isSigned;
        const int   gradeSign;
        const int   gradeExec;
};

std::ostream& operator << (std::ostream &os, const Form& obj);