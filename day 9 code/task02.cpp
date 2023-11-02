#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter a number which is less than and equal to 100 only: ";
    cin >> n;

    while (n > 100) {
        cout << "Wrong input. Try again." << endl;
        cout << "Enter a number which is less than and equal to 100 only: ";
        cin >> n;
    }

    cout << "Odd Numbers that are divisible by 9: [";
    for (int i = 1; i <= n; i += 2) {
        if (i % 9 == 0) {
            cout << i;
            if (i < n - 8) {
                cout << " ";
            }
        }
    }
    cout << "]" << endl;

    return 0;
}
