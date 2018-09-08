#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); //make a more rich return value
	int GetMaxTries();
	int GetBulls();
	int GetCows();
	int GetScore();
	bool isGameWon();
	int GetCurrentTry();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry();
	int MyMaxTries();
};