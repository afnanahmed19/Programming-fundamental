#include <iostream>
using namespace std;

// Function to calculate the area of a circle
float circarea(float radius) {
    const float pi = 3.14159; // Value of pi
    float area = pi * radius * radius; // Area calculation
    return area; // Return the calculated area
}

int main() {
    float radius;
    
    // Get the radius value from the user
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    
    // Call the circarea() function to calculate the area
    float area = circarea(radius);
    
    // Display the result
    cout << "The area of the circle with radius " << radius << " is: " << area << endl;
    
    return 0;
}
