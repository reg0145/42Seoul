#include "../includes/Dog.hpp"

Dog::Dog() : Animal("dog") {
	this->brain = new (std::nothrow) Brain();
	if (this->brain == NULL) {
		std::cout << "malloc error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::cout << mType << " wake up!" << std::endl;
}

Dog::Dog(const Dog &ref) : Animal(ref.mType) {
	this->brain = new (std::nothrow) Brain();
	if (this->brain == NULL) {
		std::cout << "malloc error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	this->brain = ref.brain;
	std::cout << mType << " wake up!" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << this->mType + " is sleeping... zzZ"<< std::endl;
}

Dog &Dog::operator=(const Dog &ref) {
	this->mType = ref.mType;
	this->brain = ref.brain;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "woof! woof!" << std::endl;
}
