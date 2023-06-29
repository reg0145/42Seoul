#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &ref);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &ref);

		void whoAmI();

	protected:
		enum {
			HIT_POINT = FragTrap::HIT_POINT,
			ENERGY = ScavTrap::ENERGY,
			DAMAGE = FragTrap::DAMAGE,
		};
		DiamondTrap();

	private:
		std::string mName;
};

#endif