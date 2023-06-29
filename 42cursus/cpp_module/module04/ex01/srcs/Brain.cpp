#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor!" << std::endl;
}

Brain::Brain(const Brain &ref) {
	std::memcpy(this->ideas, ref.ideas, sizeof(std::string) * (sizeof(ideas)/sizeof(*ideas)));
	std::cout << "Brain constructor!" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor!" << std::endl;
}

Brain &Brain::operator=(const Brain &ref) {
	std::memcpy(this->ideas, ref.ideas, sizeof(std::string) * (sizeof(ideas)/sizeof(*ideas)));
	return *this;
}

