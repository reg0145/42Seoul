#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	this->mHitPoints = 100;
	this->mEnergy = 100;
	this->mDamage = 30;
	std::cout << "<" << this->mName << "> FragTrap constructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref) {
	std::cout << "<" << this->mName << "> FragTrap constructor!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "<" << this->mName << "> FragTrap destructor!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ref) {
	this->mName = ref.mName;
	this->mHitPoints = ref.mHitPoints;
	this->mEnergy = ref.mEnergy;
	this->mDamage = ref.mDamage;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (mHitPoints > 0) {
		std::cout << "FragTrap " << this->mName << " highFivesGuys!" << std::endl;
	} else {
		std::cout << "FragTrap " << this->mName << " died!" << std::endl;
	}
}