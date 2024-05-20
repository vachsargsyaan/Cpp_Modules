#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap &other);
        ~ClapTrap();
    public:
        ClapTrap &operator=(const ClapTrap &other);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
    public:
        int         getHit();
        int         getEnergy();
        int         getAttack();
        std::string getName();

        void        setHit(unsigned int Hit);
        void        setEnergy(unsigned int Energy);
        void        setAttack(unsigned int Attack);
        void        setName(std::string Name);
        void        showInfo() const;
    private:
        std::string  Name;
        unsigned int Hit;
        unsigned int Energy;
        unsigned int Attack;
};