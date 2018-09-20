#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:

	FBullCowGame(); // constructor

	void Reset(); //make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool isGameWon() const;
	// rethink methods to use
	int32 GetBulls();
	int32 GetCows();
	int32 GetScore();
	bool CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString Guess);
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
