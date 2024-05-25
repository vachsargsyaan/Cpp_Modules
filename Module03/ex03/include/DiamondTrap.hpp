#pragma once

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    public :
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &other);
        ~DiamondTrap();
    public:
        DiamondTrap& operator =(const DiamondTrap& other);
        void whoAmI();
    private:
        std::string _name_;
};