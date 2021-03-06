/* Class containing game components, header file */

#pragma once
#include <string>

//to make syntax Unreal friendly
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
	FString GetMyHiddenword() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	FBullCowCount SubmitValidGuess(FString);
	void SetHiddenWord(int32);
	void Reset();
	
private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
