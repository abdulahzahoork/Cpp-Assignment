// Write a Circle class that has the following member variables:
// •	 radius—a double
// •	 pi—a double initialized with the value 3.14159
// The class should have the following member functions:
// •	 Default Constructor—a default constructor that sets radius to 0.0
// •	 Constructor—accepts the radius of the circle as an argument
// •	 setRadius—a mutator function for the radius variable
// •	 getRadius—an accessor function for the radius variable
// •	 getArea—returns the area of the circle, which is calculated as
// area = pi * radius * radius
// •	 getDiameter—returns the diameter of the circle, which is calculated as
// diameter = radius * 2
// •	 getCircumference—returns the circumference of the circle, which is calculated as
// circumference = 2 * pi * radius
// Write a program that demonstrates the Circle class by asking the user for the circle’s radius, creating a Circle object, then reporting the circle’s area, diameter, and
// circumference

#include <iostream>
using namespace std;

class Circle {

private:
    double radius;
    const double pi = 3.14159;

public:
    Circle() {
        radius = 0.0;
    }

    Circle(double r) {
        radius = r;
    }

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() {
        return radius;
    }

    double getArea() {
        return pi * radius * radius;
    }

    double getDiameter() {
        return radius * 2;
    }

    double getCircumference() {
        return 2 * pi * radius;
    }
};

int main() {
    Circle circle;
    double r;

    cout << "Enter the radius of the circle: ";
    cin >> r;
    circle.setRadius(r);

    cout << "Area: " << circle.getArea() << endl;
    cout << "Diameter: " << circle.getDiameter() << endl;
    cout << "Circumference: " << circle.getCircumference() << endl;

    return 0;
}