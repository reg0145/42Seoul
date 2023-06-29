#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

#define INPUT_ERR "Error: bad input => "
#define NODATE_ERR "Error: no such date."
#define FILEOPEN_ERR "Error: could not open file."
#define NOTPOSITIVE_ERR "Error: not a positive number."
#define TOOLARGEVALUE_ERR "Error: too large a number."

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(char *target, std::string data);
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange &operator=(const BitcoinExchange &ref);
		~BitcoinExchange();

		void execute();
	private:
		std::map<std::string, float> _data;
		std::string _dataFilename;
		std::string _targetFilename;

		std::map<std::string, float> parseData(std::string filename);
		std::pair<std::string, float> parseTargetLine(std::string line);
		std::string checkValidDate(std::string date);
		float checkValidValue(std::string value);
		void printResult(std::pair<std::string, float> data);
};

#endif
