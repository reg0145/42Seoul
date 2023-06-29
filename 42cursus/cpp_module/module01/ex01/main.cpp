#include "Zombie.hpp"

int main(void)
{
	const int ZOMBIE_COUNT = 10;

	Zombie* horde = zombieHorde(ZOMBIE_COUNT, "Horde");
	if (horde == NULL)
		return (EXIT_FAILURE);
	for (int i = 0; i < ZOMBIE_COUNT; i++) {
		horde[i].announce();
	}
	delete []horde;
}