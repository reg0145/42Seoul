#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &ref);
		~FragTrap();

		FragTrap &operator=(const FragTrap &ref);

		void highFivesGuys(void);

	protected:
		enum {
			HIT_POINT = 100,
			ENERGY = 100,
			DAMAGE = 30,
		};

		FragTrap();
};

#endif
