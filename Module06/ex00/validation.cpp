#include "ScalarConverter.hpp"

static int onlydigit_f(const std::string &str, int mode)
{
	if (mode)
	{
		for (size_t i = 0; i < str.length(); ++ i)
		{
			if (str[i] < '0' || str[i] > '9')
				return 0;
		}
	}
	if (!mode)
	{
		int count_f = 0;
		for (size_t i = 0; i < str.length(); ++ i)
		{
			if (str[i] == 'f')
				++ count_f;
			else if (str[i] < '0' || str[i] > '9')
				return 0;
		}
		return !(count_f > 1);
	}
	return 1;
}

static int pars_flaot(const std::string &str)
{
	std::string preDotDigits = str.substr(0, str.find(".", 0));
	std::string postDotDigits = str.substr(str.find(".", 0) + 1);
	if (preDotDigits.empty() || postDotDigits.empty() || (postDotDigits.length() == 1) \
								|| !onlydigit_f(preDotDigits, 1) || !onlydigit_f(postDotDigits, 0))
		return 0;
	return 1;
}

static int pars_double(const std::string &str)
{
	std::string preDotDigits = str.substr(0, str.find(".", 0));
	std::string postDotDigits = str.substr(str.find(".", 0) + 1);
	if (preDotDigits.empty() || postDotDigits.empty() || !onlydigit_f(preDotDigits, 1)  || !onlydigit_f(postDotDigits, 1))
		return 0;
	return 1;
}
static int pars_init(const std::string &str)
{
    if (!onlydigit_f(str, 1))
		return 0;
	return 1;
}

int validation(const std::string &str)
{
    if (str == "-inff" || str == "-inf" || str == "+inff" || str == "+inf" || str == "nanf" || str == "nan")
		return 1;
	size_t i = 0;
    while (i < str.length() && (str[i] == ' ' || str[i] == '\t'))
		++i;
    if (str[i] == '+' || str[i] == '-')
        ++i;
    if (isdigit(str[i]) && (str.find(".", i) != std::string::npos) && (str.find("f", i) != std::string::npos) && str.length() > 3)
		return (pars_flaot(&str[i]));
    if (isdigit(str[i]) && (str.find(".", i) != std::string::npos) && str.length() > 2)
		return (pars_double(&str[i]));
    else if (isdigit(str[i]) && (str.find(".", i) == std::string::npos) && (str.find("f", i) == std::string::npos))
		return (pars_init(&str[i]));
    else if (str.length() == 1)
        return 1;
    else
        return 0;
}