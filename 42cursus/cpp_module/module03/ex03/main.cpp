#include "DiamondTrap.hpp"

int main (void) {
	DiamondTrap a("A");
	DiamondTrap b("B");
	DiamondTrap c(a);

	a.attack("B");
	b.takeDamage(30);
	b.attack("A");
	a.takeDamage(30);

	a.attack("B");
	b.takeDamage(30);
	a.attack("B");
	b.takeDamage(30);
	a.attack("B");
	b.takeDamage(30);
	a.attack("B");
	b.takeDamage(30);
	b.attack("A");
	a.beRepaired(10);
	b.beRepaired(10);

	a.guardGate();
	a.highFivesGuys();
	b.guardGate();
	b.highFivesGuys();
	
	a.whoAmI();
	b.whoAmI();
}