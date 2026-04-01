// Write a class named Car that has the following member variables:
// •	 yearModel—an int that holds the car’s year model
// •	 make—a string that holds the make of the car
// •	 speed—an int that holds the car’s current speed
// VideoNote
// Solving the
// Employee
// Class Problem
// Programming Challenges 841
// In addition, the class should have the following constructor and other member
// functions:
// •	 Constructor—The constructor should accept the car’s year model and make as arguments. These values should be assigned to the object’s yearModel and make member
// variables. The constructor should also assign 0 to the speed member variables.
// •	 Accessor—appropriate accessor functions to get the values stored in an object’s
// yearModel, make, and speed member variables
// •	 accelerate—The accelerate function should add 5 to the speed member variable each time it is called.
// •	 brake—The brake function should subtract 5 from the speed member variable
// each time it is called.
// Demonstrate the class in a program that creates a Car object, then calls the accelerate
// function five times. After each call to the accelerate function, get the current speed
// of the car and display it. Then, call the brake function five times. After each call to the
// brake function, get the current speed of the car and display it.

#include <iostream>
using namespace std;

class Car {

private:
    int yearModel;
    string make;
    int speed;

public: 
    Car(int year, string mk) {
        yearModel = year;
        make = mk;
        speed = 0;
    }

    int getYearModel() {
        return yearModel;
    }

    string getMake() {
        return make;
    }

    int getSpeed() {
        return speed;
    }

    void accelerate() {
        speed += 5;
    }

    void brake() {
        speed -= 5;
    }
};

int main() {
    Car car(2020, "Toyota");

    cout << "Accelerating..." << endl;
    for (int i = 0; i < 5; i++) {
        car.accelerate();
        cout << "Current speed: " << car.getSpeed() << " mph" << endl;
    }

    cout << "Braking..." << endl;
    for (int i = 0; i < 5; i++) {
        car.brake();
        cout << "Current speed: " << car.getSpeed() << " mph" << endl;
    }

    return 0;
}