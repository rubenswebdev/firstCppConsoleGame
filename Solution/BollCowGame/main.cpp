#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main() {
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	
	return 0;
}

void PlayGame() {
	BCGame.Reset();

	int32 lifes = BCGame.GetMaxTries();

	for (int32 i = 1; i <= lifes; i++) { //TODO make a while instead a for for tries
		FText Guess = GetGuess(); 
		
		EWordStatus Status = BCGame.CheckGuessValidity(Guess);
		
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << " Cows: " << BullCowCount.Cows;
		std::cout << std::endl;
	}
}

FText GetGuess() { //TODO validar o que foi escrito antes de considerar uma tentativa
	//pergunto pro cara o chute dele
	std::cout << "Try " << BCGame.GetCurrentTry() << " Digite sua tentativa: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintIntro() {
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "Bem vindo ao joguinho da vaca e do boi" << std::endl;
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