#pragma once
#include <string>

using FString = std::string;
using int32 = int;

enum class EWordStatus {
	OK,
	NOT_OK,
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
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	void Reset();

	//TODO uma funcao para validar o que o player digitou
	//TODO uma funcao para incrementar o numero de tentativas caso tenha errado
	//TODO uma funcao para verificar as cows and bulls
	EWordStatus CheckGuessValidity(FString Guess);
	FBullCowCount SubmitGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};