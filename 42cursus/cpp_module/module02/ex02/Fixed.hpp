#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
private:
	static const int kFractionalBits = 8;
	int mFixedPoint;

public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &);
	~Fixed();

	Fixed &operator=(const Fixed &);

	bool operator>(Fixed const&) const;
	bool operator<(Fixed const&) const;
	bool operator>=(Fixed const&) const;
	bool operator<=(Fixed const&) const;
	bool operator==(Fixed const&) const;
	bool operator!=(Fixed const&) const;

	Fixed operator+(const Fixed &);
	Fixed operator-(const Fixed &);
	Fixed operator+();
	Fixed operator-();
	Fixed operator*(const Fixed &) const;
	Fixed operator/(const Fixed &) const;
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int     getRawBits(void) const;
	void    setRawBits(int const);
	float   toFloat(void) const;
	int     toInt(void) const;

	static Fixed& min(Fixed &, Fixed &);
	static Fixed& max(Fixed &, Fixed &);
	static const Fixed& min(const Fixed &, const Fixed &);
	static const Fixed& max(const Fixed &, const Fixed &);
};

std::ostream &operator<<(std::ostream&, const Fixed&);

#endif