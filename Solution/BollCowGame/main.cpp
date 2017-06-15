#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
void PrintSumario();
void EscolhaDificuldade();

FBullCowGame BCGame;

int main() {
	do {
		PrintIntro();
		EscolhaDificuldade();
		PlayGame();
	} while (AskToPlayAgain());
	
	return 0;
}

void EscolhaDificuldade() {
	BCGame.Reset();

	std::cout << "Escolha uma das dificuldades abaixo:\n";
	std::cout << "4) Facil\n";
	std::cout << "5) Medio\n";
	std::cout << "6) Dificil\n\n";

	int32 result = 4;

	FString Dif;
	std::getline(std::cin, Dif);
	std::stringstream(Dif) >> result;

	BCGame.SetDificuldade(result);

	return;
}

void PlayGame() {
	int32 lifes = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= lifes) {
		FText Guess = GetGuess(); 
		
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << " Cows: " << BullCowCount.Cows;
		std::cout << std::endl;
	}

	PrintSumario();
}

void PrintSumario() {
	if (BCGame.IsGameWon()) {
		std::cout << "[WON] Good JOB! You win!\n";
	} else {
		std::cout << "[LOSE] Good luck on the next time!\n";
	}

	return;
}

FText GetGuess() {
	EGuessStatus Status;

	do {
		
		std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << " Digite sua tentativa: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status) {

			//nao é isograma
			case EGuessStatus::NOT_ISO:
				std::cout << "Nao pode repetir letras!\n\n";
				break;

			//nao é apenas minusculas
			case EGuessStatus::NOT_LOWER:
				std::cout << "Insira somente letras minusculas!\n\n";
				break;

			//tamanho da palavra incorreta
			case EGuessStatus::WRONG_LENGTH:
				std::cout << "Insira uma palavra de " << BCGame.GetHiddenWordLength() << " letras\n\n";
				break;

			default: 
				return Guess;
		}

	} while (Status != EGuessStatus::OK);
}

void PrintIntro() {
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "\nBem vindo ao joguinho da vaca e do boi" << std::endl;
	std::cout << "Consegue adivinhar a palavra de " << WORD_LENGTH << " letras?" << std::endl;
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain() {
	std::cout << "Quer jogar novamente? (y/[n])";
	FText Response;
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}