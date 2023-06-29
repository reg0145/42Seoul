
template <typename T>
Array<T>::Array() : mSize(0), mElements(new T()) {}

template <typename T>
Array<T>::Array(unsigned int n) : mSize(n), mElements(new (std::nothrow)T[n])
{
	if (mElements == NULL)
	{
		std::cerr << "malloc error" << std::endl;
		exit(EXIT_FAILURE);
	}
}

template <typename T>
Array<T>::Array(const Array &ref)
{
	mSize = ref.mSize;
	mElements = new (std::nothrow)T[ref.mSize];
	if (mElements == NULL)
	{
		std::cerr << "malloc error" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::memcpy(mElements, ref.mElements, sizeof(T) * mSize);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &ref)
{
	if (this != &ref)
	{
		delete[] mElements;
		mSize = ref.mSize;
		mElements = new (std::nothrow)T[mSize];
		if (mElements == NULL)
		{
			std::cerr << "malloc error" << std::endl;
			exit(EXIT_FAILURE);
		}
		std::memcpy(mElements, ref.mElements, sizeof(T) * mSize);
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] mElements;
}

template <typename T>
int& Array<T>::operator[] (int idx)
{
	if(idx < 0 || (size_t)idx >= mSize)
	{
		throw std::exception();
	}
	return mElements[idx];
}

template <typename T>
size_t Array<T>::size() const
{
	return mSize;
}
