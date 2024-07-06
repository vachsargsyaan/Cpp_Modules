#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// int main ( int, char** ) {
//     try {
//         const Bureaucrat * John = new Bureaucrat("John", 11);
//         Form * A88 = new Form("A88", 15, 1409);

//         std::cout << *John;
//         std::cout << *A88;

//         John->signForm(*A88);
    
//         delete John;
//         delete A88;
//     } catch (std::exception & reason) {
//         std::cout << reason.what();
//     }
//     return (0);
// }

int main() 
{
	try
	{
		Bureaucrat b1("b1", 13);
		std::cout << b1 <<std::endl;
		Form f1("b1", 15, 36);
		std::cout << f1 <<std::endl;
		f1.beSigned(b1);
		std::cout << f1 <<std::endl;
		b1.signForm(f1);
	}
	catch(const std::exception& ex)
	{
		std::cout<<ex.what()<<std::endl;
	}
	std::cout<<std::endl;
	try
	{
		Bureaucrat b2("b1", 17);
		std::cout << b2 <<std::endl;
		Form f2("b1", 15, 36);
		std::cout << f2 <<std::endl;
		b2.signForm(f2);
		f2.beSigned(b2);
		std::cout << f2 <<std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cout<<ex.what()<<std::endl;
	}
	return (0);
}