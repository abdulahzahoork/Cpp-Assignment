// Design a Length class that has two member variables: meters and centimeters. The
// class should have a constructor, an accessor, and mutator functions for the member
// variables and a member function getLength() that returns the length in centimeters.
// Demonstrate the class by writing a separate program that creates two instances of the
// class. The program should ask the user to enter the lengths in meters and centimeters,
// which are stored in the Length objects. The program should then compare the lengths
// of the two objects with the help of the getLength member function.

#include <iostream>
using namespace std;

class Length {

private:
    int meters;
    int centimeters;

public: 
    Length() {
        meters = 0;
        centimeters = 0;
    }

    Length(int m, int cm) {
        meters = m;
        centimeters = cm;
    }

    void setMeters(int m) {
        meters = m;
    }

    void setCentimeters(int cm) {
        centimeters = cm;
    }

    int getMeters() {
        return meters;
    }

    int getCentimeters() {
        return centimeters;
    }

    int getLength() {
        return (meters * 100) + centimeters;
    }
};

int main() {
    Length length1, length2;
    int m, cm;

    cout << "Enter length 1 (meters and centimeters): ";
    cin >> m >> cm;
    length1.setMeters(m);
    length1.setCentimeters(cm);

    cout << "Enter length 2 (meters and centimeters): ";
    cin >> m >> cm;
    length2.setMeters(m);
    length2.setCentimeters(cm);

    if (length1.getLength() > length2.getLength()) {
        cout << "Length 1 is greater than Length 2." << endl;
    } else if (length1.getLength() < length2.getLength()) {
        cout << "Length 2 is greater than Length 1." << endl;
    } else {
        cout << "Length 1 and Length 2 are equal." << endl;
    }

    return 0;
}