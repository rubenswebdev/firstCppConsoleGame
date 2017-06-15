#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return bGameWon; }
int32 FBullCowGame::GetHiddenWordLength() { return GetHiddenWord().length(); }
int32 FBullCowGame::GetDificuldade() const { return Dificuldade; }

int32 FBullCowGame::GetMaxTries() { 
	TMap<int32, int32> MaxTries{ {4, 6}, {5, 8}, {6, 10} };
	return MaxTries[GetHiddenWord().length()];
}

void FBullCowGame::SetDificuldade(int32 D) {
	Dificuldade = D;
	return;
}

bool FBullCowGame::IsIsogram(FString Guess) const { 

	//percorrer cada letra salvar se ela ja existe
	//quando detectar que ja existe simplesmente retornar que nao é um isograma
	//se conseguir passar por todas as letras sem acha repetida é um isograma

	if (Guess.length() <= 1) return true;

	TMap<char, bool> LetterSeen;

	for (char Letter : Guess) {
			
		Letter = tolower(Letter);

		if (LetterSeen[Letter]) {
			return false;
		} else {
			LetterSeen[Letter] = true;
		}
	}

	return true; 
}

void FBullCowGame::Reset()
{
	OpcoesPalavras = { { 4, "monk" }, { 5, "junky" }, { 6, "planet" } };
	Dificuldade = 4;
	MyCurrentTry = 1;
	bGameWon = false;

	return;
}

FString FBullCowGame::GetHiddenWord() {
	return OpcoesPalavras[Dificuldade];
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::WRONG_LENGTH;
	} else if (!IsIsogram(Guess)) {
		return EGuessStatus::NOT_ISO;
	} else if (!IsLowercase(Guess)) {
		return EGuessStatus::NOT_LOWER;
	} else {
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//incrementa as tentivas
	MyCurrentTry++;

	//Cria o objeto para retorno
	FBullCowCount BullCowCount;

	int32 WordLength = OpcoesPalavras[Dificuldade].length();
	int32 GuessLength = Guess.length();

	for (int32 i = 0; i < WordLength; i++) {
		for (int32 j = 0; j < GuessLength; j++) {
			if (OpcoesPalavras[Dificuldade][i] == Guess[j]) {
				if (i == j) {
					BullCowCount.Bulls++;
				} else {
					BullCowCount.Cows++;
				}
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) {
		bGameWon = true;
	}

	return BullCowCount;
}

bool FBullCowGame::IsLowercase(FString Word) const {
	for (auto Letter : Word) {
		if (!islower(Letter)) return false;
	}

	return true;
}
