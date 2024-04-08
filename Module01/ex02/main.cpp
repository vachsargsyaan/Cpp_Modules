#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string	&strPEF = str;
	std::cout << &str << "\n";
	std::cout << strPTR << "\n";
	std::cout << &strPEF << "\n";
	std::cout << str << '\n';
	std::cout << *strPTR << "\n";
	std::cout << strPEF << "\n";
}