#pragma once

#define _ERROR_ARGUMENTS_ "Error: The number of arguments does not meet the requirements."
#define _ERROR_DIV_ZERO_ "Error: Cannot divide by 0"
#define _ERROR_EMPTY_ "Error: Empty argument."
#define _ERROR_INPUT_ "Error: Bad input."

#include <iostream>
#include <stack>
#include <algorithm>

class RPN
{
    public:
    	static void Reverse_Polish_Notation(char *arg);
    private:
    	static std::stack<int> st;
    
    private:
    	RPN();
    	RPN(const RPN& other);
    	RPN& operator =(const RPN& other);
    	~RPN();
    
    private:
    	static bool valid_arg(const std::string& arg);
    	static void cut_space(std::string& arg);
    	static void calc(char c);
};