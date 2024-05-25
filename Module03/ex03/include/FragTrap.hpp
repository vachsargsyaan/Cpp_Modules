#pragma once

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap &other);
        virtual ~FragTrap();
    public:
        void    highFivesGuys(void);
        FragTrap&	operator=(const FragTrap &other);

};
