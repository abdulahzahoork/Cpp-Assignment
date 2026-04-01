// Design a class named Angle. The class should have a single data member of integer
// data type named degree to represent the angle in degrees whose value ranges from 0
// to 359 degrees.
// The class should have the following member functions:
// •	 A default constructor that sets degree to 0.
// •	 A constructor that accepts an integer variable as an argument and sets degree to
// the value of the argument. If the argument value is not within the range, display an
// error message and set degree to 0.
// •	 A function setAngle that prompts the user to input the angle in degrees. If the user
// inputs a value beyond the range of 0–359, then add or subtract sufficient multiples
// of 360 so that degree is within this range.
// •	 A function getAngle that displays the angle in degrees.
// The class should also have the following overloaded operators:
// •	 Increment operator should increment degree by 1. If the value of degree becomes
// 360, set degree to 0.
// •	 Decrement operator should decrement degree by 1. If the value of degree become
// 21, set degree to 359.
// •	 Addition operator should return an Angle object whose degree is the sum of the
// degree of two Angle objects.
// •	 Subtraction operator should return an Angle object whose degree is the difference
// of the degree of two Angle objects.
// Demonstrate the class in a program.

#include <iostream>
using namespace std;

class Angle {
private:
    int degree;

public:
    Angle() : degree(0) {}

    Angle(int d) {
        if (d < 0 || d >= 360) {
            cout << "Invalid angle! Setting to 0." << endl;
            degree = 0;
        } else {
            degree = d;
        }
    }

    void setAngle() {
        int d;
        cout << "Enter angle in degrees (0-359): ";
        cin >> d;
        while (d < 0 || d >= 360) {
            if (d < 0) {
                d += 360;
            } else if (d >= 360) {
                d -= 360;
            }
        }
        degree = d;
    }

    void getAngle() const {
        cout << "Angle: " << degree << " degrees" << endl;
    }

    // Prefix increment
    Angle& operator++() {
        degree++;
        if (degree >= 360) {
            degree = 0;
        }
        return *this;
    }

    // Postfix increment
    Angle operator++(int) {
        Angle temp = *this; 
        ++(*this); 
        return temp; 
    }

    // Prefix decrement
    Angle& operator--() {
        degree--;
        if (degree < 0) {
            degree = 359;
        }
        return *this;
    }

    // Postfix decrement
    Angle operator--(int) {
        Angle temp = *this; 
        --(*this); 
        return temp;
    }

    // Addition operator
    Angle operator+(const Angle& other) const {
        return Angle((degree + other.degree) % 360);
    }

    // Subtraction operator
    Angle operator-(const Angle& other) const {
        int result = degree - other.degree;
        if (result < 0) {
            result += 360;
        }
        return Angle(result);
    }
};

int main() {
    Angle a1(30);
    Angle a2(350);

    cout << "Initial angles:" << endl;
    a1.getAngle();
    a2.getAngle();

    cout << "\nTesting increment and decrement:" << endl;
    ++a1; 
    a2--; 

    cout << "After incrementing a1 and decrementing a2:" << endl;
    a1.getAngle();
    a2.getAngle();

    cout << "\nTesting addition and subtraction:" << endl;
    Angle a3 = a1 + a2; 
    Angle a4 = a1 - a2;

    cout << "a1 + a2: ";
    a3.getAngle();

    cout << "a1 - a2: ";
    a4.getAngle();

    return 0;
}