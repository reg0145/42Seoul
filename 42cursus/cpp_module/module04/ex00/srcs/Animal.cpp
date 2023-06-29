#include "../includes/Animal.hpp"

Animal::Animal() : mType("Animal"){
	std::cout << "Animal wake up!" << std::endl;
}

Animal::Animal(const Animal &ref) : mType(ref.mType) {
	std::cout << "Animal wake up!" << std::endl;
}

Animal::Animal(const std::string type) : mType(type) {
	std::cout << "Animal wake up!" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal is sleeping... zzZ" << std::endl;
}

Animal &Animal::operator=(const Animal &ref) {
	this->mType = ref.mType;
	return *this;
}

std::string Animal::getType(void) const {
	return this->mType;
}

void Animal::makeSound() const {
	std::cout << "Animal Sound!" << std::endl;
}
