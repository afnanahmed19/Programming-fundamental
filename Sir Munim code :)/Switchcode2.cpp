#include<iostream>
using namespace std;

int main() {
	int hours, parkingCharges;
	char vehicleType;
	cout << "Enter (c) for car , (b) for bus , (t) for truck : ";
	cin >> vehicleType;
	cout << "Parking charges per hour : " << endl << "10/- for car parking" << endl << "25/- for bus parking" << endl << "40/- for truck parking" << endl;
	cout << "Enter the number of hours to be reserved for parking : ";
	cin >> hours;
	
	// Solved by SWITCH-CASE
	switch(vehicleType) {
		case 'C':
		case 'c':
			parkingCharges = hours * 10;
			cout << "Your total parking charges are : " << parkingCharges;
			break;
		case 'B':
		case 'b':
			parkingCharges = hours * 25;
			cout << "Your total parking charges are : " << parkingCharges;
			break;
		case 'T':
		case 't':
			parkingCharges = hours * 40;
			cout << "Your total parking charges are : " << parkingCharges;
			break;
		default:
			cout << "Incorrect Vehicle Type entered...";
	}
	
	/* sir
	// Solved by equivalent IF-ELSE
	if(vehicleType == 'c' || vehicleType == 'C') {
		parkingCharges = hours * 10;
		cout << "Your total parking charges are : " << parkingCharges;
	} else if(vehicleType == 'b' || vehicleType == 'B') {
		parkingCharges = hours * 25;
		cout << "Your total parking charges are : " << parkingCharges;
	} else if(vehicleType == 't' || vehicleType == 'T') {
		parkingCharges = hours * 40;
		cout << "Your total parking charges are : " << parkingCharges;
	} else {
		cout << "Incorrect Vehicle Type entered...";
	}
	*/
}