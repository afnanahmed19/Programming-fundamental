#include <iostream>
using namespace std;
int main() {
    int year;

    // Ask the user for input
    cout << "Please enter a year: ";
    scin >> year;

    // Check if it's a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is a Leap Year!" << endl;
    } else {
        cout << year << " is not a Leap Year." << endl;
    }

    return 0;
}
