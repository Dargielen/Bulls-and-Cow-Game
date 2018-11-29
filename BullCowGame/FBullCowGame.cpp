#include "pch.h"
#include "FBullCowGame.h"
#include <map>
#include <algorithm>
#define TMap std::map

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

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

int32 FBullCowGame::GetBulls()
{
	return 0;
}

int32 FBullCowGame::GetCows()
{
	return 0;
}

int32 FBullCowGame::GetScore()
{
	return 0;
}
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 4;
	const FString HIDDEN_WORD = "ante";
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) 
	{		
			return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase; // TODO make a function
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
	if (MyCurrentTry <= MyMaxTries) {
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
