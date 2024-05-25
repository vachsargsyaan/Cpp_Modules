#pragma once

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap &other);
        ~FragTrap();
    public:
        void    highFivesGuys(void);
        FragTrap&	operator=(const FragTrap &other);

};
