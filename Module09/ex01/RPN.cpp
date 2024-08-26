#include "RPN.hpp"

std::stack<int> RPN::st;

RPN::RPN(){}
RPN::RPN(const RPN& other){ (void)other; }
RPN::~RPN(){}
RPN& RPN::operator =(const RPN& other){ (void)other; return *this; }

void RPN::cut_space(std::string& arg)
{
	std::string::iterator it = arg.begin();
	while (it != arg.end())
	{
		if (*it == ' ')
			it = arg.erase(it);
		else
			++it;
	}
}
bool RPN::valid_arg(const std::string& arg)
{
	std::string::const_iterator it = arg.begin();
	const std::string valid = "1234567890 /*-+";
	for (; it != arg.end(); ++ it)
		if ((std::isdigit(*it) && std::isdigit(*(it + 1))) || (valid.find(*it, 0) == std::string::npos) \
			|| (valid.substr(valid.size() - 4, 4).find(*it, 0) != std::string::npos && std::isdigit(*(it + 1))))
			return false;
	return true;
}

void RPN::calc(char c)
{
	int num2 = RPN::st.top();
	RPN::st.pop();
	int num1 = RPN::st.top();
	RPN::st.pop();
	switch (c)
	{
		case '+':
			RPN::st.push(num1 + num2);
			break;
		case '-':
			RPN::st.push(num1 - num2);
			break;
		case '*':
			RPN::st.push(num1 * num2);
			break;
		case '/':
			if (!num2)
			{
				std::cerr << _ERROR_DIV_ZERO_ << std::endl;
				std::exit(1);
			}
			RPN::st.push(num1 / num2);
			break;
	}
}

void RPN::Reverse_Polish_Notation(char *arg)
{
	std::string str(arg);
	if (str.empty())
		throw std::runtime_error(_ERROR_EMPTY_);
	if (!valid_arg(str))
		throw std::runtime_error(_ERROR_INPUT_);
	cut_space(str);
	std::string::iterator it = str.begin();
	for ( ; it != str.end(); ++ it)
	{
		if (std::isdigit(*it))
			RPN::st.push(*it - '0');
		else if (RPN::st.size() > 1)
			calc(*it);
		else
			throw std::runtime_error(_ERROR_INPUT_);
	}
	if (RPN::st.size() != 1)
		throw std::runtime_error(_ERROR_INPUT_);
	std::cout << "Resulte : " << RPN::st.top() << std::endl;
}