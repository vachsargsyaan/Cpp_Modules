#include "phonebook.hpp"

int main()
{
	PhoneBook		obj;
	int				i;
	int				count;
	std::string		input;		

	i = 0;
	count = 0;
	while (1)
	{
		std::cout << "Command ADD: Added new Contact." << "\n";
		std::cout << "Command SEARCH: searching and showing Contacts." << "\n";
		std::cout << "Command EXIT: Closing programm." << "\n";
		std::cout << "Input Command : ";
		getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nExit the program! " << "You pressed ctrl+D." << "\n";
			exit (0);
		}
		else if (input == "EXIT")
			exit (0);
		else if (input == "ADD")
		{
			obj.add(i);
			i++;
			if (count < 8)
				count++;
			if (i == 8)
			 i = 0;
		}
		else if (input == "SEARCH")
			obj.search(count);
	}
	return 0;
}
