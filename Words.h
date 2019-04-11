#pragma once

#include <vector>
#include <unordered_map>

class Words
{

public:
	static Words *getInstance();
	std::vector<std::string> getWords(std::string level);

private:
	Words();
	static Words *singletonInstance;
	std::unordered_map<std::string, std::vector<std::string>> mapOfWords;
	std::vector<std::string> split(const std::string& str, const std::string& delim);
};

