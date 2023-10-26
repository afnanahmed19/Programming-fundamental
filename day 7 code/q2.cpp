#include <iostream>

int main() {
    int year;

    // Ask the user for input
    std::cout << "Please enter a year: ";
    std::cin >> year;

    // Check if it's a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        std::cout << year << " is a Leap Year!" << std::endl;
    } else {
        std::cout << year << " is not a Leap Year." << std::endl;
    }

    return 0;
}
