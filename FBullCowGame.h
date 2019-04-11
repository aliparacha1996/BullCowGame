#pragma once
#include <string>
#include <list> 
#include <iterator> 
#include <vector>

class FBullCowGame
{
public:
	FBullCowGame();
	void PrintIntro();
	void PlayGame();

private:
	int wordLength;
	int maxTries;
	std::string wordToGuess;
	std::vector<std::string> words;

	bool InterpretGuess(std::string guess, std::string wordToGuess);
	bool ContinuePlaying();
	bool validGuess(std::string);
	std::string GetAndPrintGuess(int num);
	void SelectDifficulty();
}	
;

