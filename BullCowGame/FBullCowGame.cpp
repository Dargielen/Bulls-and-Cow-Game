#include "pch.h"
#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	return;
}

int FBullCowGame::GetBulls()
{
	return 0;
}

int FBullCowGame::GetCows()
{
	return 0;
}

int FBullCowGame::GetScore()
{
	return 0;
}

bool FBullCowGame::isGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
