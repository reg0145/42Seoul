#include "FragTrap.hpp"

int main (void) {
	FragTrap a("A");
	FragTrap b("B");

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
	b.guardGate();
}