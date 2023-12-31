#include <iostream>

int main() {
    double num1, num2, num3;

    // Ask the user to enter three numbers
    std::cout << "Please enter the first number: ";
    std::cin >> num1;
    
    std::cout << "Please enter the second number: ";
    std::cin >> num2;

    std::cout << "Please enter the third number: ";
    std::cin >> num3;

    // Determine the greatest number
    double greatest = num1; // Assume the first number is the greatest initially

    if (num2 > greatest) {
        greatest = num2;
    }

    if (num3 > greatest) {
        greatest = num3;
    }

    // Display the result
    std::cout << "The greatest number among " << num1 << ", " << num2 << ", and " << num3 << " is: " << greatest << std::endl;

    return 0;
}
