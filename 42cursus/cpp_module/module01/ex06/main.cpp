#include "Harl.hpp"

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cout << "Please put only one parameter." << std::endl;
		return 1;
	}

	Harl harl;
	harl.complain(std::string(av[1]));
}
