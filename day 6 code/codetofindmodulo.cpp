
#include <iostream>

int main() {
    int dividend, divisor;

    // Input the dividend
    std::cout << "Enter the dividend: ";
    std::cin >> dividend;

    // Input the divisor
    std::cout << "Enter the divisor: ";
    std::cin >> divisor;

    if (divisor != 0) {
        int remainder = dividend % divisor;
        std::cout << "The remainder of " << dividend << " divided by " << divisor << " is: " << remainder << std::endl;
    } else {
        std::cout << "Error: Division by zero is not allowed." << std::endl;
    }

    // Wait for a key press before exiting
    std::cout << "Press any key to exit...";
    return 0;

}
