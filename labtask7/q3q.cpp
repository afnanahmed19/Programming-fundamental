#include <iostream>
using namespace std;

// Function to set the smaller of two integers to 0
void zerosmaller(int &a, int &b) {
    if (a < b) {
        a = 0;
    } else {
        b = 0;
    }
}

int main() {
    int num1, num2;

    // Get two integer values from the user
    cout << "Enter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;

    // Call the zerosmaller() function to set the smaller value to 0
    zerosmaller(num1, num2);

    // Display the updated values
    cout << "After processing, the values are: " << num1 << " and " << num2 << endl;

    return 0;
}
