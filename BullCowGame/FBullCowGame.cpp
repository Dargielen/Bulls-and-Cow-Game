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

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	return;
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

bool FBullCowGame::isGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
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
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
			// if they match then
			if (Guess[i] == MyHiddenWord[i]) {
				// if they're in the same place
				if (i == j) {	
					BullCowCount.Bulls++;	// increment bulls
				}
				else {					
					BullCowCount.Cows++;	// increment cows
				}
			}
		}
	}
	return BullCowCount;
}
