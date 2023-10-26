#include <iostream>
using namespace std;

int main() {
    int totalClasses, attendedClasses;

    // Ask the user for the number of classes held and attended
    cout << "Please enter the total number of classes held: ";
    cin >> totalClasses;

    cout << "Please enter the number of classes you've attended: ";
    scin >> attendedClasses;

    // Calculate attendance percentage
    double attendancePercentage = (static_cast<double>(attendedClasses) / totalClasses) * 100;

    // Check if the attendance meets the requirements
    if (attendancePercentage >= 75.0) {
        cout << "Your attendance percentage is " << attendancePercentage << "%, and you are allowed to sit in the exam." << endl;
    } else {
        cout << "Your attendance percentage is " << attendancePercentage << "%, and you do not meet the requirements to sit in the exam." << endl;
    }

    return 0;
}
