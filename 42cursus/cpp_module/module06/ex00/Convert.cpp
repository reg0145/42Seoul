#include "Convert.hpp"

Convert::Convert(const std::string &input) : mInput(input), mValue(std::strtod(mInput.c_str(), NULL)) {}

Convert::Convert(const Convert &ref)
{
	*this = ref;
}

Convert::~Convert() {}

Convert &Convert::operator=(const Convert &ref) {
	if (this != &ref)
	{
		mInput = ref.mInput;
		mValue = ref.mValue;
	}
	return *this;
}

void Convert::toChar()
{
	char ch = static_cast<char>(mValue);

	if (mValue != mValue)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (mValue >= 32 && mValue <= 126)
	{
		std::cout << "char: '" << ch << "'" << std::endl;
		return ;
	}
	if (mValue >= CHAR_MIN && mValue <= CHAR_MAX)
	{
		std::cout << "char: non displayable" << std::endl;
		return ;
	}
	std::cout << "char: impossible" << std::endl;
}

void Convert::toInt()
{
	int integer = static_cast<int>(mValue);

	if (mValue != mValue)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (mValue >= std::numeric_limits<int>::lowest() && mValue <= std::numeric_limits<int>::max())
	{
		std::cout << "int: " << integer << std::endl;
		return ;
	}
	std::cout << "int: impossible" << std::endl;
}

void Convert::toFloat()
{
	float f = static_cast<float>(mValue);

	if (mValue != mValue)
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (f == std::numeric_limits<float>::infinity())
	{
		std::cout << "float: inff" << std::endl;
		return ;
	}
	if (f == -std::numeric_limits<float>::infinity())
	{
		std::cout << "float: -inff" << std::endl;
		return ;
	}
	if (mValue >= std::numeric_limits<float>::lowest() && mValue <= std::numeric_limits<float>::max())
	{
		if (mValue == ceil(mValue))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
		return ;
	}
	std::cout << "float: impossible" << std::endl;
}

void Convert::toDouble()
{
	if (mValue != mValue)
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (mValue == std::numeric_limits<double>::infinity())
	{
		std::cout << "double: inf" << std::endl;
		return ;
	}
	if (mValue == -std::numeric_limits<double>::infinity())
	{
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	if (mValue == ceil(mValue))
		std::cout << "double: " << mValue << ".0" << std::endl;
}