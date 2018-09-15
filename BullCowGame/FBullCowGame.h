#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); //make a more rich return value
	int GetMaxTries() const;
	int GetBulls();
	int GetCows();
	int GetScore();
	bool isGameWon();
	int GetCurrentTry() const;
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
