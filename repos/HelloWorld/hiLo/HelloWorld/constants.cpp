#include <iostream>
#include "random.h" // for random number generation

int randomNumber() {
	
	int randInt{ Random::get(1, 100) };
	return randInt;

}

int hiLoGame() {
	int randInt{ Random::get(1, 100) };
	bool x{ true };
	int guesses{ 1 };
	int input{};
	char in{};
	int min{}, max{};
	int modifiedGuess{};

	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
	std::cout << "Would you like to modify the min/max number and tries you're getting? (y/n) ";
	std::cin >> in;
	while (true) {
		if (in == 'y')
		{
			std::cout << "please enter min value you want: ";
			std::cin >> min;
			std::cout << "please enter max value you want: ";
			std::cin >> max;
			std::cout << "please enter how many times you want to guess in number: ";
			std::cin >> modifiedGuess;
			break;
		}
		else if (in == 'n')
		{
			std::cout << "You're playing with default configuration\n";
			modifiedGuess = guesses;
			break;
		}
		else
		{
			modifiedGuess = guesses;
			continue;
		}
	}

	while (x <= modifiedGuess) {
		std::cout << "Guess #" << guesses << ": ";
		std::cin >> input;

		if (guesses >= modifiedGuess)
		{
			std::cout << "Sorry, you lose. The correct number was " << randInt << ".\n";
			break;
		}

		if (input == randInt)
		{
			std::cout << "Correct! You win!\n";
			x = false;
		}
		else if (input < randInt) {
			std::cout << "Your guess is too low.\n";
			++guesses;
			continue;
		}
		else if (input > randInt) {
			std::cout << "Your guess is too high.\n";
			++guesses;
			continue;
		}
	}
	return true;
}

int main()
{

	hiLoGame();

	char wantsToPlayAgain{ };

	while (true) {
	
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> wantsToPlayAgain;

		if (wantsToPlayAgain == 'y')
		{
			hiLoGame();
		}
		else if (wantsToPlayAgain == 'n')
		{
			break;
		}
	}


	return 0;
}