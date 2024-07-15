#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(const std::string& name, const int gradeSign, const int gradeExec);
        AForm(const AForm& other);
        virtual ~AForm();
    public:
        AForm& operator=(const AForm& other);
    public:
        static bool const INITIAL_SIGN_STATE = false;
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
        void    executeForm(Bureaucrat const & target) const;
        void    checkExec(Bureaucrat const & executor) const;
        void    checkSign() const;
        void    beSigned(const Bureaucrat& b1);
        void    CheckThrow(const int grade) const;
	protected:
		 virtual void execute(Bureaucrat const & executor) const = 0;
    private:
        void checkGrade( int ) const;
    private:
        std::string const name;
        bool        isSigned;
        const int   gradeSign;
        const int   gradeExec;
};

std::ostream& operator << (std::ostream &os, const AForm& obj);