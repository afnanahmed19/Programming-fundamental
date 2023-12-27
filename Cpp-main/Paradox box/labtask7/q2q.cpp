#include <iostream>
using namespace std;

// Function to swap two integer values
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1, num2;
    
    // Get two integer values from the user
    cout << "Enter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;
    
    // Call the swap() function to interchange the values
    swap(num1, num2);
    
    // Display the swapped values
    cout << "After swapping, the values are: " << num1 << " and " << num2 << endl;
    
    return 0;
}
