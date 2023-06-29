#include "Fixed.hpp"

Fixed::Fixed() : mFixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integerPart) {
	std::cout << "Int constructor called" << std::endl;
	this->mFixedPoint = integerPart << kFractionalBits;
}

Fixed::Fixed(const float floatingPoint) {
	std::cout << "Float constructor called" << std::endl;
	this->mFixedPoint = roundf(floatingPoint * (float)(1 << kFractionalBits));
}

Fixed::Fixed(const Fixed &ref) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->mFixedPoint = ref.mFixedPoint;
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->mFixedPoint;
}

void Fixed::setRawBits(const int raw) {
	this->mFixedPoint = raw;
}

float   Fixed::toFloat(void) const {
	return (float)this->mFixedPoint / (1 << kFractionalBits);
}

int     Fixed::toInt(void) const {
	return this->mFixedPoint >> kFractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &ref) {
	return os << ref.toFloat();
}