#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : mHitPoints(10), mEnergy(10), mDamage(0), mName(name) {
	std::cout << "<" << this->mName << "> ClapTrap constructor!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref) : mHitPoints(ref.mHitPoints), mEnergy(ref.mEnergy), mDamage(ref.mDamage), mName(ref.mName) {
	std::cout << "<" << this->mName << "> ClapTrap constructor!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "<" << this->mName << "> ClapTrap destructor!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref) {
	this->mHitPoints = ref.mHitPoints;
	this->mDamage = ref.mDamage;
	this->mEnergy = ref.mEnergy;
	this->mName = ref.mName;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (mEnergy > 0 && mHitPoints > 0) {
		std::cout << "ClapTrap " << this->mName << " attacks " << target << ", causing [" << this->mDamage << "] points of damage!" << std::endl;
		mEnergy--;
	} else {
		std::cout << "ClapTrap " << this->mName << " can't attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (mHitPoints > 0) {
		std::cout << "ClapTrap " << this->mName << " took [" << amount << "] damage!" << std::endl;
		this->mHitPoints -= amount;
	} else {
		std::cout << "ClapTrap " << this->mName << " already died!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (mHitPoints > 0 && mEnergy > 0) {
		std::cout << "ClapTrap " << this->mName << " repairs [" << amount << "] hitPoint!" << std::endl;
		mEnergy--;
	} else {
		std::cout << "ClapTrap " << this->mName << " can't repaired!" << std::endl;
	}
}