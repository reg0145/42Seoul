#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal wake up!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref) {
	this->mType = ref.mType;
	std::cout << "WrongAnimal wake up!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal is sleeping... zzZ" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref) {
	this->mType = ref.mType;
	return *this;
}

void WrongAnimal::makeSound(void) const {
	return ;
}