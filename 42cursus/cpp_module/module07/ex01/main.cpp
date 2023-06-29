#include <iostream>
#include "iter.hpp"

int main(void)
{
	int     int_arr[] = {10, 20, 30, 40, 50};
	float   float_arr[] = {10.1f, 20.2f, 30.3f, 40.4f, 50.5f};
	double  double_arr[] = {1e+50, 1e+51, 1e+52, 1e+53, 1e+54};

	iter(int_arr, sizeof(int_arr) / sizeof(int), printValue);
	iter(float_arr, sizeof(float_arr) / sizeof(float), printValue);
	iter(double_arr, sizeof(double_arr) / sizeof(double), printValue);

	return (0);
}