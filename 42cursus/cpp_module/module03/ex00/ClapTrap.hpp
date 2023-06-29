#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &ref);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &ref);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		int mHitPoints;
		int mEnergy;
		int mDamage;
		std::string mName;

	protected:
		ClapTrap();
};

#endif