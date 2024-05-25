#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string& _name);
        ~ScavTrap();
    public:
        void guardGate();
        void    attack(const std::string& target);
        ScavTrap&	operator=(const ScavTrap &other);
};