#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : mType("wronganimal") {
	std::cout << "WrongAnimal wake up!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : mType(type) {
	std::cout << "WrongAnimal wake up!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref) : mType(ref.mType) {
	std::cout << "WrongAnimal wake up!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal is sleeping... zzZ" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref) {
	this->mType = ref.mType;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->mType;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal sound!" << std::endl;
}