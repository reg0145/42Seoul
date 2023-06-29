#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./main [string decimal]" << std::endl;
		return EXIT_FAILURE;
	}

	std::string input(argv[1]);
	Convert convert(input);

	convert.toChar();
	convert.toInt();
	convert.toFloat();
	convert.toDouble();

	return 0;
}
