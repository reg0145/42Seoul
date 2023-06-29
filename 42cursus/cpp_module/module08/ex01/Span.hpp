#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span {
	public:
		Span(unsigned int N);
		Span(const Span &ref);
		Span &operator=(const Span &ref);
		~Span();

		void addNumber(int number);
		void addNumber(std::vector<int> vector);
		unsigned int  shortestSpan();
		unsigned int  longestSpan();
		
	private:
		unsigned int mSize;
		std::vector<int> mVector;

		Span();
};

#endif