#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor!" << std::endl;
}

Brain::Brain(const Brain &ref) {
	std::memcpy(this->ideas, ref.ideas, sizeof(std::string) * ref.ideas->size());
	std::cout << "Brain constructor!" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor!" << std::endl;
}

Brain &Brain::operator=(const Brain &ref) {
	std::memcpy(this->ideas, ref.ideas, sizeof(std::string) * ref.ideas->size());
	return *this;
}

