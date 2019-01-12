/* Class containing game components, functions declarations */

#pragma once

#include "pch.h"
#include "FBullCowGame.h"
#include <map>
#include <algorithm>

//to make syntax Unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

FString FBullCowGame::GetMyHiddenword() const
{
	return MyHiddenWord;
}

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries { {3,5}, {4,5}, {5,5}, {6,5} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}
void FBullCowGame::SetHiddenWord(int32 MyWordLength)
{
	TMap<int32, FString> WordChosenFromLength { {3, "cat"}, { 4, "frog" }, { 5, "shirt" }, {6, "planet"}};
	MyHiddenWord = WordChosenFromLength[MyWordLength];

}

bool FBullCowGame::IsIsogram(FString Word) const
{

	if (Word.length() <= 1) { return true; }	// treat 0 and 1 letter words as isograms

	TMap<char, bool> LetterSeen; // setup our map
	for (auto Letter : Word)	// for all letters of the word
	{
		Letter = tolower(Letter);	// handle mixed case
		if (LetterSeen[Letter]) {	
			return false;	}
		else {	
			LetterSeen[Letter] = true;	// add letter to the map as seen
		}	
	}

	return true;	// assume user can input something like this: /0
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyHiddenWord = "";
	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) 
	{		
			return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}	
}
// receives a VALID guess and increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
	if (MyCurrentTry <= GetMaxTries()) {
		// loop through all letters in the hidden word
		for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
		{// compare letters against the guess
			for (int32 GChar = 0; GChar < WordLength; GChar++)
			{// if they match then
				if (Guess[GChar] == MyHiddenWord[MHWChar])
				{// if they're in the same place
					if (MHWChar == GChar)
					{
						BullCowCount.Bulls++;	// increment bulls
					}
					else
					{
						BullCowCount.Cows++;	// increment cows
					}
				}
			}
		}
		MyCurrentTry++;
	}
	if (BullCowCount.Bulls == WordLength) 
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}
