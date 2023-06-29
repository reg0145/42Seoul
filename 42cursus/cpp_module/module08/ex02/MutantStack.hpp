#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack();
		MutantStack(MutantStack const &src);
		~MutantStack();
		MutantStack<T>& operator=(MutantStack const &src);

		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif
