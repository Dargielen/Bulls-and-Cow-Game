#pragma once

class FBullCowGame {
public:
	void Reset(); //make a more rich return value
	int GetMaxTries();
	int GetBulls();
	int GetCows();
	int GetScore();
	bool isGameWon();
	int GetCurrentTry();
	bool CheckGuessValidity();

private:
	int MyCurrentTry();
	int MyMaxTries();
};