#include "Harl.hpp"

void	Harl::error()
{
	std::cout << "ERROR\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::debug()
{
	std::cout << "DEBUG\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info()
{
	std::cout << "INFO\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning()
{
	std::cout << "WARNING\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::print_err()
{
	std::cout << "Not coorect command\n";
	return ;
}

void	Harl::complain(std::string level)
{
	std::string arr[] = {"ERROR", "DEBUG", "INFO", "WARNING", "NULL"};
	void(Harl::*tmp[])(void) = {&Harl::error, &Harl::debug, &Harl::info, &Harl::warning};

	int i = 0;
	while (level != arr[i] && arr[i] != "NULL")
		++i;
	switch(i)
	{
		case 0:
			(this->*tmp[0])();
			break;
		case 1:
			(this->*tmp[1])();
			break;
		case 2:
			(this->*tmp[2])();
			break;
		case 3:
			(this->*tmp[3])();
			break;
		default:
			print_err();
			break;
	}
}