#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	public:
		Animal();
		Animal(std::string const type);
		Animal(const Animal &ref);
		virtual ~Animal();
		Animal &operator=(const Animal &ref);

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;

	protected:
		std::string mType;
};

#endif