#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)  name(name), weapon(&weapon) {}

void    HumanA::attack() {
	if (this->weapon == NULL)
		std::cout << this->name << " attacks with their both hands" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}