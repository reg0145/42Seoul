#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.Hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(std::string const & type);
		Ice(const Ice &ref);
		~Ice();
		Ice &operator=(const Ice &ref);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif