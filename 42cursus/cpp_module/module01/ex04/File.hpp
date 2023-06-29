#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

namespace ft{
	class File {
		private:
			std::string name;
			std::string content;

		public:
			File(char *name);

			void SaveAs(std::string fileName);
			void Replace(std::string oldChar, std::string newChar);
			std::string GetName();
	};
}

#endif
