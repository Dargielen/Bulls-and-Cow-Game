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

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Not_Lowercase,
	Wrong_Length
};

class FBullCowGame {
public:

	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	// rethink methods to use
	int32 GetBulls();
	int32 GetCows();
	int32 GetScore();

	void Reset(); //make a more rich return value
	bool isGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	FBullCowCount SubmitGuess(FString);
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
