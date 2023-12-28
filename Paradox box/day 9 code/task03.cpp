#include <iostream>

using namespace std;

int main() {
    int num, endPoint;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter the ending point: ";
    cin >> endPoint;

    cout << "Table of " << num << " up to " << endPoint << ":\n";
    
    for (int i = 1; i <= endPoint; i++) {
        cout << num << " x " << i << " = " << num * i << endl;
    }

    return 0;
}
