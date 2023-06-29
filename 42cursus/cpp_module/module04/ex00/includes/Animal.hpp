#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	public:
		Animal();
		Animal(const std::string type);
		Animal(const Animal &ref);
		virtual ~Animal();
		Animal &operator=(const Animal &ref);

		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string mType;
};

#endif