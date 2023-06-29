#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(const Dog &ref);
		virtual ~Dog();
		Dog &operator=(const Dog &ref);

		virtual void makeSound(void) const;

	private:
		Brain *brain;
};

#endif