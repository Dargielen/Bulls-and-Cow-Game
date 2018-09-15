#pragma once
#include <string>

class FBullCowGame {
public:

	FBullCowGame(); // constructor

	void Reset(); //make a more rich return value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool isGameWon() const;
	// rethink methods to use
	int GetBulls();
	int GetCows();
	int GetScore();
	bool CheckGuessValidity(std::string);
	// provide a method for counting bulls and cows, and increasing try #
private:
	int MyCurrentTry;
	int MyMaxTries;
};
