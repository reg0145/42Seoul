#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> a;

	a.push_back(1);
	a.push_back(2);

	std::cout << *easyfind(a, 1) << std::endl;

	try
	{
		std::cout << *easyfind(a, 3) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}