#include "File.hpp"

int main(int ac, char *av[]) {
	if (ac != 4) {
		std::cout << "usage: file [filename] [oldChar] [newChar]" << std::endl;
		return 1;
	}

	ft::File file(av[1]);
	file.Replace(std::string(av[2]), std::string(av[3]));
	file.SaveAs(file.GetName().append(".replace"));
}