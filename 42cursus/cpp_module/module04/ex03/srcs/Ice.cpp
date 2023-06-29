#include "../includes/Ice.hpp"

Ice::Ice() {
	this->mType = "ice";
	std::cout << "Ice constructor" << std::endl;
}

Ice::Ice(std::string const & type) {
	this->mType = type;
	std::cout << "Ice constructor" << std::endl;
}

Ice::Ice(const Ice &ref) {
	this->mType = ref.mType;
	std::cout << "Ice constructor" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor" << std::endl;
}

Ice &Ice::operator=(const Ice &ref) {
	this->mType = ref.mType;
	return *this;
}

AMateria* Ice::clone() const {
	return new Cure(this->mType);
}

void Ice::use(ICharacter& target) {
	std::cout << "* heals " << target << "'s wounds *"<< std::endl;
}