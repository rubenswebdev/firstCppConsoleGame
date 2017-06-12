#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planeta";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	if (Guess.length() != GetHiddenWordLength()) {
		return EWordStatus::WRONG_LENGTH;
	} else if (false) {
		return EWordStatus::NOT_OK;
	} else {
		return EWordStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//incrementa as tentivas
	MyCurrentTry++;

	//Cria o objeto para retorno
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();

	for (int32 i = 0; i < WordLength; i++) {
		for (int32 j = 0; j < GuessLength; j++) {
			if (MyHiddenWord[i] == Guess[j] && i == j) {
				BullCowCount.Bulls++;
			}

			if (MyHiddenWord[i] == Guess[j] && i != j) {
				BullCowCount.Cows++;
			}
		}
	}

	return BullCowCount;
}
