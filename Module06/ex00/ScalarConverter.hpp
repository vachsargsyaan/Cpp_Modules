#pragma once

#include <iostream>

class ScalarConverter
{
    public:
        static void convert(const char *argv);
        class Handel : public std::exception
        {
            public:
                const char * what() const throw();
        };
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
	    ScalarConverter& operator =(const ScalarConverter &other);
        ~ScalarConverter();
};

int validation(const std::string &str);
void char_cast(char c);
void double_cast(double num, const std::string &arg);
void float_cast(float num, const std::string &arg);
void int_cast(int num);
