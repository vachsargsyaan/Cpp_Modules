#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	public :
		void	complain(std::string level);
	private:
		void	error(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	print_err(void);
};

#endif