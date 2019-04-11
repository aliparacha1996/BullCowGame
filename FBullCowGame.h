#pragma once
#include <string>
#include <list> 
#include <iterator> 

class FBullCowGame
{
public:
	FBullCowGame(int wordLength, int maxTries);
	void PrintIntro();
	void SelectDifficulty();
	void PlayGame();

private:
	int wordLength;
	int maxTries;
	std::string wordToGuess;
	std::string words[5] = {"slope", "heat", "game", "saint", "tech"};

	bool InterpretGuess(std::string guess, std::string wordToGuess);
	bool ContinuePlaying();
	bool validGuess(std::string);
	std::string GetAndPrintGuess(int num);
}	
;

