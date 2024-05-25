#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& _name);
        ScavTrap(const ScavTrap &other);
        virtual ~ScavTrap();
    public:
        void guardGate();
        void    attack(const std::string& target);
        ScavTrap&	operator=(const ScavTrap &other);
};