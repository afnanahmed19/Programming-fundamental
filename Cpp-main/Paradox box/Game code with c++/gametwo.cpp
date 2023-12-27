#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

std::string getComputerChoice() {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % 3;

    switch (randomIndex) {
        case 0:
            return "Rock";
        case 1:
            return "Paper";
        case 2:
            return "Scissors";
    }
}

std::string getUserChoice() {
    std::string userChoice;
    std::cout << "Enter your choice (Rock, Paper, or Scissors): ";
    std::cin >> userChoice;
    return userChoice;
}

std::string determineWinner(std::string computerChoice, std::string userChoice) {
    if (computerChoice == userChoice) {
        return "It's a tie!";
    }

    if ((computerChoice == "Rock" && userChoice == "Scissors") ||
        (computerChoice == "Paper" && userChoice == "Rock") ||
        (computerChoice == "Scissors" && userChoice == "Paper")) {
        return "Computer wins!";
    } else {
        return "User wins!";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::string computerChoice = getComputerChoice();
    std::string userChoice = getUserChoice();
    std::cout << "Computer chose " << computerChoice << ". " << determineWinner(computerChoice, userChoice) << std::endl;
    return 0;
}