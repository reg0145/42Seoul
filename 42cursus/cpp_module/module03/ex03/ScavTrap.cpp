#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "<" << this->mName << "> ScavTrap constructor!" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	this->mHitPoints = HIT_POINT;
	this->mEnergy = ENERGY;
	this->mDamage = DAMAGE;
	this->mName = name;
	std::cout << "<" << this->mName << "> ScavTrap constructor!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref) {
	std::cout << "<" << this->mName << "> ScavTrap constructor!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "<" << this->mName << "> ScavTrap destructor!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref) {
	this->mHitPoints = ref.mHitPoints;
	this->mDamage = ref.mDamage;
	this->mEnergy = ref.mEnergy;
	this->mName = ref.mName;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (mEnergy > 0 && mHitPoints > 0) {
		std::cout << "ScavTrap " << this->mName << " attacks " << target << ", causing [" << this->mDamage << "] points of damage!" << std::endl;
		mEnergy--;
	} else {
		std::cout << "ScavTrap " << this->mName << " can't attack!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	if (mHitPoints > 0) {
		std::cout << "ScavTrap " << this->mName << " activates gatekeeper mode!" << std::endl;
	} else {
		std::cout << "ScavTrap " << this->mName << " can't gatekeeper mode!" << std::endl;
	}
}
