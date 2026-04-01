// Add a copy constructor to the FeetInches class. This constructor should accept a
// FeetInches object as an argument. The constructor should assign to the feet attribute the value in the argument’s feet attribute, and assign to the inches attribute the
// value in the argument’s inches attribute. As a result, the new object will be a copy of
// the argument object.
// Next, add a multiply member function to the FeetInches class. The multiply
// function should accept a FeetInches object as an argument. The argument object’s
// feet and inches attributes will be multiplied by the calling object’s feet and inches
// attributes, and a FeetInches object containing the result will be returned.

#include <iostream>
using namespace std;

class FeetInches {

private:
    int feet;
    int inches;

public:
    FeetInches(int f, int i) : feet(f), inches(i) {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    void print() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    // Copy constructor
    FeetInches(const FeetInches& other) : feet(other.feet), inches(other.inches) {}

    // Multiply function
    FeetInches multiply(const FeetInches& other) const {
        int f = feet * other.feet;
        int i = inches * other.inches;
        return FeetInches(f, i);
    }
};

int main() {
    FeetInches obj1(5, 8);
    FeetInches obj2(3, 4);

    cout << "Object 1: ";
    obj1.print();
    cout << "Object 2: ";
    obj2.print();

    // Testing copy constructor
    FeetInches obj3 = obj1; 
    cout << "Object 3 (copy of Object 1): ";
    obj3.print();

    // Testing multiply function
    FeetInches result = obj1.multiply(obj2);
    cout << "Result of multiplying Object 1 and Object 2: ";
    result.print();

    return 0;
}