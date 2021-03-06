/* BullCowGame.cpp : This file contains the 'main' function. 
   Program execution begins and ends there. */

#pragma once

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();
void AskForWordLength();
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
	std::cout << " BBB  U  U L    L      SS     A   N   N DDD    CCCC OOOO W     W  SS" << std::endl;
	std::cout << " B  B U  U L    L     S      A A  NN  N D  D   C    O  O  W   W  S"  << std::endl;
	std::cout << " BBB  U  U L    L      S     A A  N N N D  D   C    O  O  W W W   S" << std::endl;
	std::cout << " B  B U  U L    L       S   A A A N  NN D  D   C    O  O   W W     S" << std::endl;
	std::cout << " BBB  UUUU LLLL LLLL  SS    A   A N   N DDD    CCCC OOOO   W W   SS" << std::endl;
	std::cout << std::endl;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	AskForWordLength();
	std::cout << std::endl;
	int32 MaxTries = BCGame.GetMaxTries();
	// loop asking for guesses while the game is NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows <<"\n\n";
	}
	std::cout << std::endl;
	PrintGameSummary();
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
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
	std::cout << "Try " << MyCurrentTry << " of " << BCGame.GetMaxTries();
	std::cout << ". Please type your word: ";
	std::getline(std::cin, Guess);

	Status = BCGame.CheckGuessValidity(Guess);
	switch (Status)
	{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength();
			std::cout << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lowercase word.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Game won." << std::endl;
		std::cout << "Word to guess was " << BCGame.GetMyHiddenword() << std::endl;
		std::cout << "You needed " << BCGame.GetCurrentTry() - 1 << " guesses." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Game over" << std::endl;
	}
}

void AskForWordLength()
{
	int32 MyWordLength = BCGame.GetHiddenWordLength();
	FString MyAnswer;
	while (MyWordLength < 3 || MyWordLength > 6) {
		try {
			std::cout << "Please type word length (from 3 to 6 letters): ";
			std::getline(std::cin, MyAnswer);
			MyWordLength = std::stoi(MyAnswer);
		}
		catch (const std::exception& e) {
		}
	}
	BCGame.SetHiddenWord(MyWordLength);
}