#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
	public:
		Bureaucrat& operator =(const Bureaucrat& other);
	public:
		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int grade);
	public:
		void incrementGrade( void );
        void decrementGrade( void );
		void signAForm(AForm& form) const;
		void executeForm( AForm const & ) const;
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

	private:
		const std::string	name;
		int					grade;
};

std::ostream& operator<<( std::ostream &os, const Bureaucrat &obj);
