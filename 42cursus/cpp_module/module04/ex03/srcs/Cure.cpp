#include "../includes/Cure.hpp"

Cure::Cure() {
	this->mType = "cure";
	std::cout << "Cure constructor" << std::endl;
}

Cure::Cure(std::string const mType) {
	this->mType = mType;
	std::cout << "Cure constructor" << std::endl;
}

Cure::Cure(const Cure &ref) {
	this->mType = ref.mType;
	std::cout << "Cure constructor" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor" << std::endl;
}

Cure &Cure::operator=(const Cure &ref) {
	this->mType = ref.mType;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(this->mType);
}

void Cure::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target << "*" << std::endl;
}