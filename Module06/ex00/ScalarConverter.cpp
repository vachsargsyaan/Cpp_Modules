#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator =(const ScalarConverter &other)
{
    (void)other; return *this;
}

ScalarConverter::~ScalarConverter()
{}

const char * ScalarConverter::Handel::what() const throw ()
{
	return "You entered an incorrect argument";
}

void    ScalarConverter::convert(const char *argv)
{
    std::string str(argv);
    if (!validation(str))
        throw ScalarConverter::Handel();
    size_t i = 0;
    while (i < str.length() && (str[i] == ' ' || str[i] == '\t'))
        ++i;
    if (str[i] == '+' || str[i] == '-')
		++i;
    if ((isdigit(str[i]) && (str.find(".", i) != std::string::npos) && (str.find("f", i) != std::string::npos) && str.length() > 3) \
			|| str == "nanf" || str == "-inff" || str == "+inff")
		float_cast(atof(argv), argv);
	else if ((isdigit(str[i]) && (str.find(".", i) != std::string::npos) && str.length() > 2) \
			|| str == "nan" || str == "-inf" || str == "+inf")
		double_cast(atof_l(argv, NULL), argv);
	else if (isdigit(str[i]) && (str.find(".", i) == std::string::npos) && (str.find("f", i) == std::string::npos))
		int_cast(atoi(argv));
	else if (str.length() == 1)
		char_cast(*argv);

}