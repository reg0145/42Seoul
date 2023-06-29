#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *arr, size_t length, void (*f)(T const &value))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

template<typename T>
void printValue(T const &value)
{
	std::cout << value << std::endl;
}
#endif