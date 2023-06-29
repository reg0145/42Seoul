#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
	this->mName = name;
	this->mHitPoints = HIT_POINT;
	this->mEnergy = ENERGY;
	this->mDamage = DAMAGE;
	std::cout << "<" << this->mName << "> DiamondTrap constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref), ScavTrap(), FragTrap() {
	this->mName = ref.mName;
	std::cout << "<" << this->mName << "> DiamondTrap constructor!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "<" << this->mName << "> DiamondTrap destructor!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref) {
	this->mName = ref.mName;
	this->mEnergy = ref.mEnergy;
	this->mDamage = ref.mDamage;
	this->mHitPoints = ref.mHitPoints;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "ClapTrap name : " << ClapTrap::mName << std::endl;
	std::cout << "DiamondTrap name: " << this->mName << std::endl;
}