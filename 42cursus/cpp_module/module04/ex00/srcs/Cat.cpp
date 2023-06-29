#include "../includes/Cat.hpp"

Cat::Cat() : Animal("cat") {
	std::cout << this->mType + " wake up!" << std::endl;
}

Cat::Cat(const Cat &ref) : Animal(ref.mType) {
	std::cout << this->mType + " wake up!" << std::endl;
}

Cat::~Cat() {
	std::cout << this->mType + " is sleeping... zzZ" << std::endl;
}

Cat &Cat::operator=(const Cat &ref) {
	this->mType = ref.mType;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "meow~" << std::endl;
}
