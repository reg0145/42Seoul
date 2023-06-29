#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main(void)
{
	{
		const Animal *animal = new (std::nothrow) Animal();
		const Animal *dog = new (std::nothrow) Dog();
		const Animal *cat = new (std::nothrow) Cat();

		if (animal == NULL || dog == NULL || cat == NULL)
		{
			std::cout << "malloc error" << std::endl;
			std::exit(EXIT_FAILURE);
		}

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;

		animal->makeSound();
		dog->makeSound();
		cat->makeSound();
		
		delete animal;
		delete dog;
		delete cat;
	}
	{
		const WrongAnimal *wrongAnimal = new (std::nothrow)WrongAnimal();
		const WrongAnimal *wrongCat = new (std::nothrow)WrongCat();

		if (wrongAnimal == NULL || wrongCat == NULL)
		{
			std::cout << "malloc error" << std::endl;
			std::exit(EXIT_FAILURE);
		}

		std::cout << wrongCat->getType() << " " << std::endl;
		
		wrongCat->makeSound();
		wrongAnimal->makeSound();

		delete wrongAnimal;
		delete wrongCat;
	}
	return 0;
}
