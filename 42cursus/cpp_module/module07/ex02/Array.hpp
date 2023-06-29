#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &ref);
		~Array();
		Array &operator=(const Array &ref);
		int& operator[] (int idx);
		size_t    size() const;

	private:
		size_t mSize;
		T *mElements;
};

#include "Array.tpp"

#endif