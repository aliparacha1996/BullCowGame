#include "pch.h"
#include "Words.h"
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <regex>


Words* Words::singletonInstance = NULL;

 Words* Words::getInstance()
{
	if (!singletonInstance)
		singletonInstance = new Words;
	return singletonInstance;
}

 std::vector<std::string> Words::getWords(std::string level)
 {
	 return mapOfWords.at(level);
 }

Words::Words()
{
	std::string line;
	std::ifstream myfile("IsogramWordCSVFiles\\words.csv");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::vector<std::string> list = split(line, ",");
			std::pair<std::string, std::vector<std::string>> pair(list[0], list);
			mapOfWords.insert(pair);
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
}

std::vector<std::string> Words::split(const std::string & str, const std::string & delim)
{
	std::vector<std::string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == std::string::npos) pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}
