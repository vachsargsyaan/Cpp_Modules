#pragma once

#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int& grade);
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
	public:
		class GradeTooLowException
		{
			public:
				GradeTooLowException();
				~GradeTooLowException() throw();
			public:
				const char * what() const throw();
			private:
			std::string	_errMsg;
		};
		class GradeTooHigeException
		{
			public:
				GradeTooHigeException();
				~GradeTooHigeException() throw();
			public:
				const char * what() const throw();
			private:
			std::string	errMsg;
		};
	private:
		const std::string	name;
		int					grade;
};
