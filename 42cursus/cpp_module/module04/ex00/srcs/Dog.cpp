#include "../includes/Dog.hpp"

Dog::Dog() : Animal("dog") {
	std::cout << mType << " wake up!" << std::endl;
}

Dog::Dog(const Dog &ref) {
	this->mType = ref.mType;
}

Dog::~Dog() {
	std::cout << this->mType + " is sleeping... zzZ"<< std::endl;
}

Dog &Dog::operator=(const Dog &ref) {
	this->mType = ref.mType;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "woof! woof!" << std::endl;
}
