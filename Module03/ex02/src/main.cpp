#include "FragTrap.hpp"

int main()
{
    std::string name = "Jimi";
	std::string name2 = "ROBOT";
	FragTrap robot_1(name2);
    FragTrap robot_2(name);
	robot_1.showInfo();
    robot_1.attack("tree");
    robot_1.attack("enemy");
    robot_1.attack("another enemy");
    robot_1.takeDamage(1);
    robot_1.takeDamage(1);
    robot_1.takeDamage(1);
    robot_1.beRepaired(1);
    robot_1.beRepaired(1);
    robot_1.beRepaired(1);
    robot_1.showInfo();

    std::cout << std::endl;
    robot_2.attack("ATTACKEDDDD!!!");
    std::cout << std::endl;
    robot_2.highFivesGuys();
    std::cout << std::endl;
   	return (0);	
}