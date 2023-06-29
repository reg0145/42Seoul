#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(const Brain &ref);
		~Brain();
		Brain &operator=(const Brain &ref);

		std::string ideas[100];
};

#endif