#include <iostream>

int main() {
    int totalClasses, attendedClasses;

    // Ask the user for the number of classes held and attended
    std::cout << "Please enter the total number of classes held: ";
    std::cin >> totalClasses;

    std::cout << "Please enter the number of classes you've attended: ";
    std::cin >> attendedClasses;

    // Calculate attendance percentage
    double attendancePercentage = (static_cast<double>(attendedClasses) / totalClasses) * 100;

    // Check if the attendance meets the requirements
    if (attendancePercentage >= 75.0) {
        std::cout << "Your attendance percentage is " << attendancePercentage << "%, and you are allowed to sit in the exam." << std::endl;
    } else {
        std::cout << "Your attendance percentage is " << attendancePercentage << "%, and you do not meet the requirements to sit in the exam." << std::endl;
    }

    return 0;
}
