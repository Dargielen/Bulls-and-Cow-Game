// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();
bool AskToPlayAgain();
FText GetValidGuess();

FBullCowGame BCGame; // instatiate a new game

// the entry point for our application
int main()
{
	bool bWantsToPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		bWantsToPlayAgain = AskToPlayAgain();
	} while (bWantsToPlayAgain);
		
	return 0;
}

void PrintIntro()
{
	// introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking about?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// loop asking for guesses while the game is NOT won
	// uand there are still tries remaining
	while (!BCGame.isGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows <<"\n\n";
	}
	// TODO summarise game
	std::cout << std::endl;
	//std::cout << "Game won." << std::endl;
	PrintGameSummary();
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? With same hidden word (y/n)";
	std::cout << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}
// loop continually until a user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
	// get a guess from the player
	int32 MyCurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << MyCurrentTry << ". Please type your word: ";
	std::getline(std::cin, Guess);

	Status = BCGame.CheckGuessValidity(Guess);
	switch (Status)
	{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lowercase word.\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void PrintGameSummary()
{
	if (BCGame.isGameWon())
	{
		std::cout << "Game won." << std::endl;
	}
	else
	{
		std::cout << "Game over" << std::endl;
	}

}