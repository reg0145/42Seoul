#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cmath>
#include <limits>
#include <stdlib.h>
#include <iostream>

class Convert {
	public:
		Convert(const std::string &input);
		Convert(const Convert &ref);
		~Convert();


		void toChar(void);
		void toInt(void);
		void toFloat(void);
		void toDouble(void);

	private:
		Convert();
		Convert &operator=(const Convert &ref);

		std::string mInput;
		double mValue;
};

#endif