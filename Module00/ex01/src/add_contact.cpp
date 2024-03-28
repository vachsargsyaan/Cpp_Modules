#include "phonebook.hpp"

void	PhoneBook::add_first_name(int i)
{
	std::string	str;

	while (1)
	{
		std::cout << "Enter First Name : ";
		getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "\nExit the program! " << "You pressed ctrl+D." << "\n";
			exit (0);
		}
		else if (str.empty() || only_space(str))
		{
			std::cout << "Not correct First Name\n";
			continue;
		}
		Contact[i].set_first_name(str);	
		break;
	}
}
void 	PhoneBook::add_last_name(int i)
{
	std::string	str;

	while (1)
	{
		std::cout << "Enter Last Name : ";
		getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "\nExit the program! " << "You pressed ctrl+D." << "\n";
			exit (0);
		}
		else if (str.empty() || only_space(str))
		{
			std::cout << "Not correct Last Name\n";
			continue;
		}
		Contact[i].set_last_name(str);	
		break;
	}
}

void	PhoneBook::add_phone_number(int i)
{
	std::string	str;

	while (1)
	{
		std::cout << "Enter Phone Number : ";
		getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "\nExit the program! " << "You pressed ctrl+D." << "\n";
			exit (0);
		}
		else if (str.empty() || only_space(str) || correct_phone_number(str))
		{
			std::cout << "Not correct Phone Number\n";
			continue;
		}
		Contact[i].set_phone_number(str);	
		break;
	}
}

void	PhoneBook::add(int i)
{
	std::string	str;

	PhoneBook::add_first_name(i);
	PhoneBook::add_last_name(i);
	PhoneBook::add_phone_number(i);
	std::cout << "Enter Nickname : ";
	getline(std::cin, str);
	Contact[i].set_nickname(str);
	std::cout << "Darkest Secret : ";
	getline(std::cin, str);
	Contact[i].set_darkest_secret(str);
	std::cout << "Contact added successfully.\n";
}
