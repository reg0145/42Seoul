#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal &ref);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &ref);

		void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string mType;
};

#endif