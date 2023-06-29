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
		Fixed(const Fixed &ref);
		~Fixed();
		Fixed &operator=(const Fixed &ref);

		int     getRawBits(void) const;
		void    setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;
};

std::ostream &operator<<(std::ostream&, const Fixed&);

#endif