#include "Zombie.hpp"

int main(void) {
	Zombie *normal_zombie = newZombie("Normal");
	normal_zombie->announce();

	Zombie *heavy_zombie = newZombie("Heavy");
	heavy_zombie->announce();

	randomChump("Voodoo");

	delete heavy_zombie;
	delete normal_zombie;
}