#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &ref);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &ref);

		void attack(const std::string &target);
		void guardGate();

	protected:
		enum {
			HITPOINT = 100,
			ENERGY = 50,
			DAMAGE = 20,
		};
		ScavTrap();
};

#endif