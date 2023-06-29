#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

#define MAX_ANIMAL 10

int main(void) {
	{
		const Animal *dog = new(std::nothrow) Dog();
		const Animal *cat = new(std::nothrow) Cat();

		if (dog == NULL || cat == NULL) {
			std::cout << "malloc error" << std::endl;
			std::exit(EXIT_FAILURE);
		}

		dog->makeSound();
		cat->makeSound();
		
		delete dog;
		delete cat;
	}

	{
		Animal *animals[MAX_ANIMAL];
		for (int i = 0; i < MAX_ANIMAL; i++) {
			if (i % 2 == 0)
				animals[i] = new(std::nothrow) Cat();
			else
				animals[i] = new(std::nothrow) Dog();
			if (animals[i] == NULL) {
				std::cout << "malloc error" << std::endl;
				for (int j = 0; j < i; j++) {
					delete animals[i];
				}
				std::exit(EXIT_FAILURE);
			}
		}

		for (int i = 0; i < MAX_ANIMAL; i++) {
			std::cout << animals[i]->getType() << " : ";
			animals[i]->makeSound();
		}

		for (int i = 0; i < MAX_ANIMAL; i++) {
			delete animals[i];
		}
	}
	return 0;
}
