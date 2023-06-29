#include <iostream>

int main(void)
{
	std::string A = "HI THIS IS BRAIN";
	std::string *A_ptr = &A;
	std::string &A_ref = A;

	std::cout << "Address A     : " << &A << std::endl;
	std::cout << "Address A_ptr : " << A_ptr << std::endl;
	std::cout << "Address A_ref : " << &A_ref << std::endl;

	std::cout << "Value A       : " << A << std::endl;
	std::cout << "Value A_ptr   : " << *A_ptr << std::endl;
	std::cout << "Value A_ref   : " << A_ref << std::endl;
}

