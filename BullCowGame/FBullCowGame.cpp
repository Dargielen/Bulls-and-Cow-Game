#include "pch.h"
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

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
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "ante";
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	return;
}

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}
// receives a VALID guess and increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	// loop through all letters in the guess
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) 
	{
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) 
		{
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				// if they're in the same place
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
	return BullCowCount;
}
