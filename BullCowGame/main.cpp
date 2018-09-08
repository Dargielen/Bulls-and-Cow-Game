// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>


void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std::string GetGuess();

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
	constexpr int WORD_LENGTH = 6;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking about?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;
	// loop for the number of turns asking for guesses
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		std::string Guess = GetGuess();
		// repeat the guess back to them
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::cout << std::endl;
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

std::string GetGuess()
{
	// get a guess from the player
	std::cout << "Please type your word: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}