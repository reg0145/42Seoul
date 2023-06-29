#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.Hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(std::string const & type);
		Cure(const Cure &ref);
		~Cure();
		Cure &operator=(const Cure &ref);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif