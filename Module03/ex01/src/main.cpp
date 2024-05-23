#include "ScavTrap.hpp"

int main()
{
    std::string name = "rob-bot";
	ScavTrap robot_1(name);
    ScavTrap robot_2;
	robot_1.showInfo();
    robot_1.attack("tree");
    robot_1.attack("enemy");
    robot_1.attack("another enemy");
    robot_1.takeDamage(99);
    robot_1.takeDamage(1);
    robot_1.takeDamage(1);
    robot_1.beRepaired(2);
    robot_1.beRepaired(2);
    robot_1.beRepaired(2);
    robot_1.showInfo();

    robot_2 = robot_1;
    robot_2.showInfo();
   	return (0);	
}