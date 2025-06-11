#include "HumanA.hpp"
#include <iostream>


HumanA::HumanA(std::string name, Weapon& weap) : _name(name), _weapon(weap) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}   