#include "phonebook.hpp"

bool	PhoneBook::correct_phone_number(std::string _phone_number_)
{
	size_t i = 0;

	while (i < _phone_number_.length())
	{
		if (!std::isdigit(_phone_number_[i]))
			return true;
		i++;
	}
	return false;
}

bool	PhoneBook::only_space(std::string _space_)
{
	size_t i = 0;

	while (i < _space_.length())
	{
		if (_space_[i] != ' ')
			return false;
		i++;
	}
	return true;
}

void	PhoneBook::pars_set_dot(std::string &s1, std::string s2)
{
	if (s2.length() > 10)
		s1 = (s2.substr(0, 9) + '.');
	else
		s1 = s2;
}

void	PhoneBook::search(int count)
{
	int 		index = 0;
	std::string	tmp;
	std::string	output;
	if (count == 0)
	{
		std::cout << "You don't have Contact\n";
		return ;
	}

	std::cout << "|  index  | First name | Last name | Nickname |\n";
	for (int j = 0; j < count; ++j)
	{
		std::cout << " ---------- ---------- ---------- ----------" << "\n";
		std::cout << "|" << std::setw(10) << j << "|" << std::setw(10);
		pars_set_dot(output, Contact[j].get_first_name());
		std::cout <<  output << "|" << std::setw(10);
		pars_set_dot(output, Contact[j].get_last_name());
		std::cout <<  output << "|" << std::setw(10);
		pars_set_dot(output, Contact[j].get_nickname());
		std::cout <<  output << "|" << "\n";
	}
	std::cout << " ---------- ---------- ---------- ----------" << "\n";
	while (1)
	{
		std::cout << "Enter index to display information : ";
		getline(std::cin, tmp);
	
	
		index = std::atoi(tmp.c_str());
		if (index >= count || tmp.empty() || index < 0 || std::isalpha(tmp[0]))
		{
			std::cout << "You entered an incorrect index!!!" << "\n";
			continue ;
		}
		std::cout << "\n";
		break ;
	}
	std::cout << "Firs Name : " << Contact[index].get_first_name() << "\n";
	std::cout << "Last Name : " << Contact[index].get_last_name() << "\n";
	std::cout << "Nickame : " << Contact[index].get_nickname() << "\n";
	std::cout << "Phone Number : " << Contact[index].get_phone_number() << "\n";
	std::cout << "Darkest Secret : " << Contact[index].get_darkest_secret() << "\n";
	std::cout << "\n";
}
