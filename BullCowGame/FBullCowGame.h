#pragma once
#include <string>

class FBullCowGame {
public:

	FBullCowGame(); // constructor

	void Reset(); //make a more rich return value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool isGameWon() const;

	int GetBulls();
	int GetCows();
	int GetScore();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
};
