#include "../includes/Cat.hpp"

Cat::Cat() : Animal("cat") {
	this->brain = new (std::nothrow) Brain();
	if (this->brain == NULL) {
		std::cout << "malloc error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::cout << this->mType + " wake up!" << std::endl;
}

Cat::Cat(const Cat &ref) : Animal(ref.mType) {
	this->brain = new (std::nothrow) Brain();
	if (this->brain == NULL) {
		std::cout << "malloc error" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	this->brain = ref.brain;
	std::cout << this->mType + " wake up!" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << this->mType + " is sleeping... zzZ" << std::endl;
}

Cat &Cat::operator=(const Cat &ref) {
	this->mType = ref.mType;
	this->brain = ref.brain;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "meow~" << std::endl;
}
