template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src)
{
	this = src;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const &src)
{
	if (this != &src)
	{
		this = src;
	}
	return *this;
}

