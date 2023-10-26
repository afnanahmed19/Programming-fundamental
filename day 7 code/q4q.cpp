#include <iostream>

int main() {
    int number;

    // Ask the user to enter a number
    std::cout << "Please enter a number: ";
    std::cin >> number;

    // Check if it's divisible by both 5 and 11
    if (number % 5 == 0 && number % 11 == 0) {
        std::cout << number << " is divisible by both 5 and 11." << std::endl;
    } else {
        std::cout << number << " is not divisible by both 5 and 11." << std::endl;
    }

    return 0;
}
