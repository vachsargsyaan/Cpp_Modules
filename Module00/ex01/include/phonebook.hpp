#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class phonebook
{
	public:
		void	add(int i);
		void	search(int count);
	private:
		contact contact[8];
		bool 	only_space(std::string _space_);
		bool	correct_phone_number(std::string _phone_number_);
		void	pars_set_dot(std::string &s1, std::string s2);
		void 	add_first_name(int i);
		void 	add_last_name(int i);
		void 	add_phone_number(int i);
};

#endif