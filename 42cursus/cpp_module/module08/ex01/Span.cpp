#include "Span.hpp"

Span::Span(unsigned int N) : mSize(N) {}

Span::Span(const Span &ref) {
	mSize = ref.mSize;
	mVector = ref.mVector;
}

Span::~Span() {}

Span &Span::operator=(const Span &ref) {
	mSize = ref.mSize;
	mVector = ref.mVector;
	return *this;
}

void Span::addNumber(int number)
{
	if (mVector.size() >= mSize)
		throw std::exception();
	mVector.push_back(number);
}

void Span::addNumber(std::vector<int> vector)
{
	if ((mVector.size() + vector.size()) > mSize)
		throw std::exception();
	mVector.insert(mVector.end(),vector.begin(), vector.end());
}

unsigned int Span::shortestSpan()
{
	if (mVector.size() < 2)
		throw std::exception();

	std::sort(mVector.begin(), mVector.end());

	unsigned int shortest = mVector[1] - mVector[0];
	std::vector<int>::iterator begin = mVector.begin();
	std::vector<int>::iterator end = mVector.end();
	for (; begin < end - 1; begin++)
	{
		if ((unsigned int)(*(begin + 1) - *(begin)) < shortest)
			shortest = *(begin + 1) - *(begin);
	}
	return shortest;
}

unsigned int Span::longestSpan()
{
	if (mVector.size() < 2)
		throw std::exception();
	std::sort(mVector.begin(), mVector.end());
	return *(mVector.end() - 1) - *mVector.begin();
}