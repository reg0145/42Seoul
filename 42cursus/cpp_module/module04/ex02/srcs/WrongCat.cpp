#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
	this->mType = "WrongCat";
	std::cout << this->mType + " wake up!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref) {
	this->mType = ref.mType;
	std::cout << this->mType + " wake up!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << this->mType + " is sleeping... zzZ"<< std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &ref) {
	this->mType = ref.mType;
	return *this;
}

void WrongCat::makeSound(void) {
	std::cout << "maa~" << std::endl;
}
