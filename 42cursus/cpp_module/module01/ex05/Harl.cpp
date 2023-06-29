#include "Harl.hpp"

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::error() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::warning() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	static const std::string log_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fp[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int idx = -1;
	while (++idx < 4 && log_levels[idx].compare(level));

	switch (idx) {
		case 0:
			(this->*fp[0])();
			break;
		case 1:
			(this->*fp[1])();
			break;
		case 2:
			(this->*fp[2])();
			break;
		case 3:
			(this->*fp[3])();
			break;
		default:
			std::cout << "..." << std::endl;
	}
}