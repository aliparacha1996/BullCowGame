#include "pch.h"
#include "FBullCowGame.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Words.h"

const int ASCII_FOR_LOWERCASE_A = 97;

FBullCowGame::FBullCowGame(int wordLength, int maxTries)
{
	this->wordLength = wordLength;
	this->maxTries = maxTries;
	Words::getInstance();
}

//Introduction to the game
void FBullCowGame::PrintIntro()
{
	std::cout << "Welcome to the Cats and Dogs game.\n\n";
}

void FBullCowGame::SelectDifficulty()
{
	bool validDifficultySelected = false;
	std::string difficulty;
	
	do {
		std::cout << "Please 1, 2 or 3 to select a difficulty level.\n";	
		getline(std::cin, difficulty);

		if (difficulty.length() > 1 || (difficulty[0] != '1' && difficulty[0] != '2' && difficulty[0] != '3'))
			std::cout << "Please select a valid difficulty.\n";
		else {
			validDifficultySelected = true;
			//words = Words::getInstance()->getWords();

			switch (difficulty[0])
			{
				case '1':
					break;
				case '2':
					break;
				default:
					break;
			}

		}

	} while (!validDifficultySelected);
}

// Get guess from user and display it back to them
std::string FBullCowGame::GetAndPrintGuess(int num)
{
	std::string guess;
	std::cout << "Enter your guess: ";
	getline(std::cin, guess);
	std::cout << "Your guess " << num << " was: " << guess << "\n\n";
	return guess;
}

// Interpret user's guess and give them feedback on their guess.
bool FBullCowGame::InterpretGuess(std::string guess, std::string wordToGuess)
{
	int presentCharacters[26] = { 0 };
	int bulls = 0;
	int cows = 0;

	for (int i = 0; i < wordToGuess.length(); i++)
		presentCharacters[wordToGuess[i] - ASCII_FOR_LOWERCASE_A] = 1;

	for (int i = 0; i < wordToGuess.length(); i++)
	{
		if (presentCharacters[guess[i] - ASCII_FOR_LOWERCASE_A] == 1)
		{
			if (guess[i] == wordToGuess[i])
				bulls++;
			else cows++;
		}
	}

	if (bulls == wordToGuess.length())
	{
		std::cout << "Congratulations! You correctly guessed the isogram.\n\n";
		return true;
	}
	else 
	{
		std::cout << "You have " << bulls << " bulls and " << cows << " cows.\n";
		return false;
	}


}

//Ask user if they want to continue playing
bool FBullCowGame::ContinuePlaying()
{
	bool correct_length = false;
	std::string userInput;

	while (!correct_length) {

		std::cout << "Press Y/y to continue or N/n to exit: ";
		getline(std::cin, userInput);
		std::cout << "\n";
		if (userInput.length() > 1 || (tolower(userInput[0]) != 'y' && tolower(userInput[0]) != 'n'))
			std::cout << "Please enter either Y/y or N/n.\n";
		else correct_length = true;
	}

	return tolower(userInput[0]) == 'y';
}

bool FBullCowGame::validGuess(std::string guess) {
	if (guess.length() != wordToGuess.length())
	{
		std::cout << "Please enter a " << wordToGuess.length() << " letter isogram.\n";
		return false;
	}
	int chars[26] = { 0 };

	for (int i = 0; i < guess.length(); i++)
	{
		if (chars[guess[i] - ASCII_FOR_LOWERCASE_A] == 1)
		{
			std::cout << "Please enter an isogram. An isogram is a word with no repeating letters.\n";
			return false;
		}
		else chars[guess[i] - ASCII_FOR_LOWERCASE_A] = 1;
	}
	return true;

}

void FBullCowGame::PlayGame()
{
	std::string guess;
	bool correctGuess;
	int i;

	do {
		srand(time(NULL));
		this->wordToGuess = words[rand() % words->length()];
		std::cout << "Can you guess the " << this->wordToGuess.length() << " letter isogram?\n\n";

		for (i = 0; i < this->maxTries; i++)
		{
			guess = GetAndPrintGuess(i + 1);			
			std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
		
			if (validGuess(guess))
			{
				correctGuess = InterpretGuess(guess, this->wordToGuess);
				if (correctGuess)
					break;
			}
			else i--;
		}

		if (i == this->maxTries)
			std::cout << "\nSorry you are out of tries. The isogram was: " << wordToGuess << "\n";
	
	} while (ContinuePlaying());
}

