#include "BitcoinExchange.hpp"

int  main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "[Usage]: ./btc <inputfile>" << std::endl;
		return 1;
	}

	BitcoinExchange exchange(argv[1], "data.csv");
	exchange.execute();

	return 0;
}
