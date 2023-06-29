#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &ref);
		~FragTrap();

		FragTrap &operator=(const FragTrap &ref);

		void highFivesGuys(void);

	protected:
		FragTrap();
};

#endif
