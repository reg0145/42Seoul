#include "ClapTrap.hpp"

int main (void) {
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(5);
	b.attack("A");
	a.takeDamage(5);
	a.beRepaired(5);
	b.beRepaired(5);

	a.attack("B");
	b.takeDamage(10);
	b.attack("A");
	a.beRepaired(10);
	b.beRepaired(10);

	int idx = -1;
	while (++idx < 6) {
		a.beRepaired(0);
	}
	a.beRepaired(0);
}