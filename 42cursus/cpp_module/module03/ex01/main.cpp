#include "ScavTrap.hpp"

int main (void) {
	ScavTrap a("A");
	ScavTrap b("B");

	a.attack("B");
	b.takeDamage(20);
	b.attack("A");
	a.takeDamage(20);

	a.attack("B");
	b.takeDamage(20);
	a.attack("B");
	b.takeDamage(20);
	a.attack("B");
	b.takeDamage(20);
	a.attack("B");
	b.takeDamage(20);
	b.attack("A");
	a.beRepaired(10);
	b.beRepaired(10);

	a.guardGate();
	b.guardGate();
}