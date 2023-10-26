#include <iostream>
using namespace std;

int main() {
    int marks;

    // Taking user input for marks
    cout << "Could you please enter your marks: ";
    cin >> marks;

    // Check for invalid input
    if (marks < 0 || marks > 100) {
        cout << "Invalid input. Marks should be between 0 and 100." << endl;
    } else {
        // Assigning grades based on the provided grading rules
        char grade;
        if (marks < 50) {
            grade = 'F';
        } else if (marks >= 50 && marks <= 55) {
            grade = 'E';
        } else if (marks >= 56 && marks <= 60) {
            grade = 'D';
        } else if (marks >= 61 && marks <= 65) {
            grade = 'C';
        } else if (marks >= 66 && marks <= 70) {
            grade = 'B';
        } else if (marks >= 71 && marks <= 80) {
            grade = 'A';
        } else {
            grade = 'A';
        }

        // Displaying the corresponding grade
        cout << "Your corresponding grade is: " << grade << endl;
    }

    return 0;
}
