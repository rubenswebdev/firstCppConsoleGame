#pragma once
#include <string>
#include <map>
#include <sstream>

#define TMap std::map

using FString = std::string;
using int32 = int;

enum class EGuessStatus {
	OK,
	NOT_ISO,
	NOT_LOWER,
	WRONG_LENGTH
};

//int32 Bulls; int32 Cows;
//Declara um tipo de dado é como se fosse um objeto no JS para ser usado como retornos
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	
	//metodo construtor
	FBullCowGame();

	//gets que nao modificam valores devem ser const, funciona sem porem é uma recomendação.
	int32 GetMaxTries();
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength();
	int32 GetDificuldade() const;
	bool IsGameWon() const;
	FString GetHiddenWord();

	void Reset();

	EGuessStatus CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString);
	void SetDificuldade(int32);

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameWon;
	int32 Dificuldade;
	TMap<int32, FString> OpcoesPalavras;

	bool IsIsogram(FString Guess) const;
	bool IsLowercase(FString Word) const;
};