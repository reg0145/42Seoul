#include "Fixed.hpp"

Fixed::Fixed() : mFixedPoint(0) {}

Fixed::Fixed(const int integerPart) {
	this->mFixedPoint = integerPart << kFractionalBits;
}

Fixed::Fixed(const float floatingPoint) {
	this->mFixedPoint = roundf(floatingPoint * (float)(1 << kFractionalBits));
}

Fixed::Fixed(const Fixed &ref) {
	*this = ref;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
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

// A = B
Fixed &Fixed::operator=(const Fixed &ref) {
	this->mFixedPoint = ref.mFixedPoint;
	return *this;
}

// A << Bc
std::ostream &operator<<(std::ostream &os, const Fixed &ref) {
	return os << ref.toFloat();
}

// A == ref
bool Fixed::operator==(Fixed const &ref) const {
	return this->mFixedPoint == ref.mFixedPoint;
}

// A != ref
bool Fixed::operator!=(Fixed const &ref) const {
	return this->mFixedPoint != ref.mFixedPoint;
}

// A > ref
bool Fixed::operator>(Fixed const &ref) const {
	return this->mFixedPoint > ref.mFixedPoint;
}

// A < ref
bool Fixed::operator<(Fixed const &ref) const {
	return this->mFixedPoint < ref.mFixedPoint;
}

// A >= ref
bool Fixed::operator>=(Fixed const &ref) const {
	return this->mFixedPoint >= ref.mFixedPoint;
}

// A <= ref
bool Fixed::operator<=(Fixed const &ref) const {
	return this->mFixedPoint <= ref.mFixedPoint;
}

// A + ref
Fixed Fixed::operator+(const Fixed &ref) {
	return Fixed(this->toFloat() + ref.toFloat());
}

// A - ref
Fixed Fixed::operator-(const Fixed &ref) {
	return Fixed(this->toFloat() - ref.toFloat());
}

// +A
Fixed Fixed::operator+() {
	return Fixed(+this->mFixedPoint);
}

// -A
Fixed Fixed::operator-() {
	return Fixed(-this->mFixedPoint);
}

// A * ref
Fixed Fixed::operator*(const Fixed &ref) const {;
	return Fixed(this->toFloat() * ref.toFloat());
}

// A / ref
Fixed Fixed::operator/(const Fixed &ref) const {
	return Fixed(this->toFloat() / ref.toFloat());
}

// ++A
Fixed &Fixed::operator++() {
	this->mFixedPoint += 1;
	return *this;
}

// A++
Fixed Fixed::operator++(int) {
	Fixed old = *this;
	operator++();
	return old;
}

// --A
Fixed &Fixed::operator--() {
	this->mFixedPoint -= 1;
	return *this;
}

// A--
Fixed Fixed::operator--(int) {
	Fixed old = *this;
	operator--();
	return old;
}

Fixed& min(Fixed &A, Fixed &B) {
	return A > B ? B : A;
}

Fixed& max(Fixed &A, Fixed &B) {
	return A > B ? A : B;
}

const Fixed& min(const Fixed &A, const Fixed &B) {
	return A > B ? B : A;
}

const Fixed& Fixed::max(const Fixed &A, const Fixed &B) {
	return A > B ? A : B;
}