#include "File.hpp"

ft::File::File(char *name) : name(std::string(name)) {}

void ft::File::SaveAs(std::string fileName) {
	std::ofstream ofstream(fileName.c_str());
	if (!ofstream.is_open()) {
		std::cout << "Error: " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
	ofstream << content;
	ofstream.close();
}

void ft::File::Replace(std::string oldChar, std::string newChar){
	std::ifstream ifstream(this->name);

	if (!ifstream.is_open()) {
		std::cout << "Error: " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
	ifstream.seekg(0, std::ios::end);
	int size = ifstream.tellg();
	this->content.resize(size);
	ifstream.seekg(0, std::ios::beg);
	ifstream.read(&content[0], size);

	size_t pos = 0;
	int oldLength = oldChar.length();
	int newLength = newChar.length();
	if (!oldChar.empty()) {
		while ((pos = this->content.find(oldChar, pos)) != std::string::npos) {
			this->content.erase(pos, oldLength);
			this->content.insert(pos, newChar);
			pos += newLength;
		}
	}
	ifstream.close();
}

std::string ft::File::GetName() {
	return this->name;
}