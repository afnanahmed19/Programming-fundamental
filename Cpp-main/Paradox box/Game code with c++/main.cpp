#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

const std::string WELCOME_MESSAGE = "Welcome to Number Guessing Game!";
const std::string INSTRUCTIONS = "I'm thinking of a number between 1 and 100. Can you guess it in 10 tries or fewer?";
const std::string PROMPT_USER = "Enter your guess: ";
const std::string CONGRATULATIONS = "Congratulations! You guessed the number in ";
const std::string GUESS_TOO_HIGH = " is too high. Try again: ";
const std::string GUESS_TOO_LOW = " is too low. Try again: ";
const std::string SORRY_YOU_LOSE = "Sorry, you've run out of tries. The number I was thinking of was ";

int getRandomNumber(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

bool validateInput(int userInput, int min, int max) {
    if (userInput < min || userInput > max) {
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        return false;
    }
    return true;
}

int playGame() {
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = getRandomNumber(1, 100);
    int userInput;
    int tries = 0;

    std::cout << WELCOME_MESSAGE << "\n";
    std::cout << INSTRUCTIONS << "\n";

    while (tries < 10) {
        std::cout << PROMPT_USER;
        std::cin >> userInput;

        if (!validateInput(userInput, 1, 100)) {
            continue;
        }

        tries++;

        if (userInput == randomNumber) {
            std::cout << CONGRATULATIONS << tries << " tries.\n";
            return 0;
        } else if (userInput > randomNumber) {
            std::cout << userInput << GUESS_TOO_HIGH;
        } else {
            std::cout << userInput << GUESS_TOO_LOW;
        }
    }

    std::cout << SORRY_YOU_LOSE << randomNumber << ".\n";
    return 0;
}
int main() {
    playGame();
    return 0;
}